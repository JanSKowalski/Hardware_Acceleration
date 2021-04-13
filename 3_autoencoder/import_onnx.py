# https://www.onnxruntime.ai/python/auto_examples/plot_load_and_predict.html
# Verify that the onnx file is correct

#Jan S Kowalski

import onnxruntime as rt
import numpy
from onnxruntime.datasets import get_example

ONNX_FILE_PATH = "/home/jan/Xilinx/Vitis_hls/u200_dev/basic_inference/src/pytorch/autoencoder.onnx"

#########################
#import the file

example1 = get_example(ONNX_FILE_PATH)
sess = rt.InferenceSession(example1)

#########################
# Let's see the input name and shape.

input_name = sess.get_inputs()[0].name
print("input name", input_name)
input_shape = sess.get_inputs()[0].shape
print("input shape", input_shape)
input_type = sess.get_inputs()[0].type
print("input type", input_type)

#########################
# Let's see the output name and shape.

output_name = sess.get_outputs()[0].name
print("output name", output_name)  
output_shape = sess.get_outputs()[0].shape
print("output shape", output_shape)
output_type = sess.get_outputs()[0].type
print("output type", output_type)

#########################
# Let's compute its outputs (or predictions if it is a machine learned model).

import numpy.random
x = numpy.random.random((1))
x = x.astype(numpy.float32)
res = sess.run([output_name], {input_name: x})
print(x, res)
