# https://michhar.github.io/convert-pytorch-onnx/
#Jan S Kowalski
# Export autoencoder as onnx
import torch
import torch.nn as nn
import torch.optim as optim
import torch.onnx
import sys

#normalized inputs
x = torch.linspace(0, 1, 200).unsqueeze(-1)
y = x

############ Define model ########################

class Model(nn.Module):
	def __init__(self):
		super(Model, self).__init__()
		self.fc1 = nn.Linear(1,3)
		self.fc2 = nn.Linear(3,3)
		self.fc3 = nn.Linear(3,1)

	def forward(self, x):
		x = self.fc1(x) # missing relu
		x = self.fc2(x) # missing relu
		x = self.fc3(x) 
		return x

model = Model()
############ Run training ########################

optimizer = optim.SGD(model.parameters(), lr=0.0001)
loss_fn = nn.MSELoss(reduction='sum')

learning_rate = 1e-6
for t in range(2000):
	optimizer.zero_grad()
	output = model(x)
	loss = loss_fn(output, y)
	loss.backward()
	optimizer.step()
    
    
############ Test results #######################
test_sequence = torch.linspace(0, 1, 9).unsqueeze(-1)

print("Test input, result")

for z in test_sequence:
	print(z, model(z))


############ Store parameter values ########################

original_stdout = sys.stdout # Save a reference to the original standard output

with open('weights.data', 'w') as f:
	sys.stdout = f # Change the standard output to the file we created.
	for param in model.parameters():
		print(param.data)
	sys.stdout = original_stdout # Reset the standard output to its original value

############ Export model as ONNX ###################

dummy_input = torch.tensor([1.0]) #torch.randn(1), used to define expected input dimensions
torch.onnx.export(model, dummy_input, "autoencoder.onnx")
