The taylor.py file generates the weights for a third-order taylor series approximating sin  

The hardware then reads those weights from weights.data and applies the following operation:
    result = w[0] + w[1]x + w[2]x**2 + w[3]x**3
