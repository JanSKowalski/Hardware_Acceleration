#https://pytorch.org/tutorials/beginner/pytorch_with_examples.html
#Jan S Kowalski
# Learn the correct weights of taylor approximation of sin through GD

import torch
import math
import sys

x = torch.linspace(-math.pi, math.pi, 5000)
y = torch.sin(x)

p = torch.tensor([1, 2, 3])
xx = x.unsqueeze(-1).pow(p)

model = torch.nn.Sequential(	torch.nn.Linear(3, 1),
    				torch.nn.Flatten(0, 1))

loss_fn = torch.nn.MSELoss(reduction='sum')

learning_rate = 1e-6
for t in range(3000):
    y_pred = model(xx)
    loss = loss_fn(y_pred, y)
    model.zero_grad()
    loss.backward()

    with torch.no_grad():
        for param in model.parameters():
            param -= learning_rate * param.grad

############ Print out results ########################

original_stdout = sys.stdout # Save a reference to the original standard output

with open('weights.data', 'w') as f:
	sys.stdout = f # Change the standard output to the file we created.
	print(model[0].bias[0].item())
	for weight in model[0].weight[0]:
		print(weight.item())
	sys.stdout = original_stdout # Reset the standard output to its original value
