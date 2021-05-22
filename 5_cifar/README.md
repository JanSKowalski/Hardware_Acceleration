## Pytorch inference

The python code comes from chapter 7 and 8 of Steven et al.'s Deep learning with PyTorch. My goal with this is to a)make sure I can write a kernel for nontrivial pytorch and b)verify that FPGA implementations shorten inference time.

### Results

Interestingly, using ReLU increased validation accuracy to 86%, compared to 80% with tanh. Both are nonlinearities, so I'm not sure why one performs better than the other for this specific task.

### Links

https://pytorch.org/assets/deep-learning/Deep-Learning-with-PyTorch.pdf
