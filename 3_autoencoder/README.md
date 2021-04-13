## Autoencoder inference

ONNX is the up-and-coming standard for dealing with ML models. Most popular frameworks support it. Although ehe main ONNX interface is python, the developers included a C/C++ API that we can [hopefully] use in conjunction with the u200 C++ calls.

Vitis-AI exists, but as of the writing of this md (April 2021) it doesn't officially support xgboost. 

Here we train an autoencoder in export_onnx.py. We then verify that we can read the model with import_onnx.py, and again in standalone_import_onnx.cpp


### Results
The standalone C ONNX reader works fine. Still working on integrating this into host.c


### Links

The specific onnx library I'm using can be found here:

https://github.com/microsoft/onnxruntime/releases/download/v1.4.0/onnxruntime-linux-x64-1.4.0.tgz


The following resources were referenced:

https://michhar.github.io/convert-pytorch-onnx/

https://www.onnxruntime.ai/python/auto_examples/plot_load_and_predict.html

https://github.com/microsoft/onnxruntime/blob/master/csharp/test/Microsoft.ML.OnnxRuntime.EndToEndTests.Capi/CXX_Api_Sample.cpp

https://github.com/microsoft/onnxruntime/issues/3095

https://github.com/lutzroeder/netron ::: https://netron.app/
