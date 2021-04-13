## Autoencoder inference

Autoencoders are a class of ML models trained to map input to output. They are largely used as placeholders, or as a security measure (see arxiv 1702.something).

In this project, we focus on ONNX. ONNX is the up-and-coming standard for handling ML models between applications, and can be accessed with the ONNXRuntime API. Although ONNXRuntime is mainly written for python, the developers included a C/C++ API that we endeavor to use. 

As possible alternative, Vitis-AI is built on top of ONNXRuntime for FPGAs. It doesn't support xgboost however (as of April 2021), so we will work directly with ONNXRuntime. 

Train the autoencoder: export_onnx.py  
Verify onnx model: import_onnx.py, standalone_import_onnx.cpp  

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
