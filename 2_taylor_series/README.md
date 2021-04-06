## Taylor series approximation

Nonlinear functions of an input x can be expressed as the weighted sum of x<sup>n</sup>, where n is any natural number

The purpose of this exercise is to practice transfering weights from a third party to the hardware for model inference. I also use quantization for the first time.

The taylor.py file generates the weights for a third-order taylor series approximating sin. The hardware then reads those weights from weights.data and applies the following operation:


    `result = w[0] + w[1]x + w[2]x^2+ w[3]x^3`

###Results:  
3000 training epochs resulted in weights that average an error of  0.0577 from true sin.  Using fixed-point then introduced additional imprecision of 0.005 (for 14b) and 0.02 (for 10b).

The following resources were referenced:
https://pytorch.org/tutorials/beginner/pytorch_with_examples.html
https://www.xilinx.com/html_docs/xilinx2020_2/vitis_doc/fixe_point_types.html#xzz1539734233552
