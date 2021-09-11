#Kaggle titanic challenge

import csv
import torch
import torch.nn as nn
import torch.optim as optim
import torch.cuda as cuda
import random
from torch.utils.data import Dataset, DataLoader
import numpy as np

validation_to_training_ratio = 0.15

raw_label_names = []
processed_data = []

train_data_path = 'train.csv'

#extract the features I want into a central array
feature_list = [1,2,4]
with open(train_data_path, 'r') as file:
    reader = csv.reader(file)
    for row in reader:
    	new_row = []
    	if (row[0] == "PassengerId"):
    		raw_label_names = row
    		continue
    	for i in feature_list:
    		#special handling for strings
    		if (i==4):
    			new_entry = 0 if (row[4]=="male") else 1		
    		else:
    			new_entry = int(row[i])
    		new_row.append(new_entry)
    	processed_data.append(new_row)

processed_data = np.asarray(processed_data, dtype=np.float32)
np.random.shuffle(processed_data)

#split into data vs. labels
processed_labels = processed_data.T[0]
processed_data = np.delete(processed_data, 0, 1)

#split the array into train/validation
split_index = int(processed_data.shape[0]*validation_to_training_ratio)
split_labels = np.split(processed_labels, [split_index])
val_labels = split_labels[0]
train_labels = split_labels[1]
split_data = np.split(processed_data, [split_index])
val_data = split_data[0]
train_data = split_data[1]

#data class for pytorch DataLoader
class Generic_Dataset(Dataset):
	def __init__(self, data, labels):
		self.data = data
		self.labels = labels
        
	def __getitem__(self, index):
		x = self.data[index]
		y = self.labels[index]
		return x, y
    
	def __len__(self):
		return len(self.data)

#load data into pytorch api
train_dataset= Generic_Dataset(train_data, train_labels)
train_loader = torch.utils.data.DataLoader(train_dataset, batch_size=64, shuffle=True)

#define model
model = nn.Sequential(
            nn.Linear(2, 30),
            nn.ReLU(),
            nn.Linear(30, 30),
            nn.ReLU(),
            nn.Linear(30, 1))
learning_rate = 1e-2
optimizer = optim.SGD(model.parameters(), lr=learning_rate)
loss_fn = nn.MSELoss()

n_epochs = 100

#allow cuda if available
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
if (torch.cuda.is_available()):
	model = model.cuda()

#train model
for epoch in range(n_epochs):
	for data, labels in train_loader:
		data = data.to(device=device)
		labels = labels.to(device=device)
		outputs = model(data).to(device=device)
		loss = loss_fn(outputs.squeeze(), labels).to(device=device)
		optimizer.zero_grad()
		loss.backward()
		optimizer.step()
	#print("Epoch: %d, Loss: %f" % (epoch, float(loss)))

#validation run
val_dataset = Generic_Dataset(val_data, val_labels)
val_loader = torch.utils.data.DataLoader(val_dataset, batch_size=64, shuffle=False)

correct = 0
total = 0

with torch.no_grad():
    for data, labels in val_loader:
        data = data.to(device=device)
        labels = labels.to(device=device)
        outputs = model(data).to(device=device)
        print(outputs)
        if (torch.cuda.is_available()):
        	outputs = outputs.cuda().round().flatten()
        else:
        	outputs = np.round(outputs, 0).flatten()
        print(outputs)
        total += labels.shape[0]
        correct += int((outputs == labels).sum())
        
print("Accuracy: %f" % (correct / total))
