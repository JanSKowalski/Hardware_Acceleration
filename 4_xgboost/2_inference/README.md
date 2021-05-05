## XGBoost inference

One step towards arbitrary inference. Classification

Run `python frontend.py` to generate hardware

There are two functions in the backend:
- generate_classification_hardware(model) 
- export_inputs_and_outputs(inputs, model_prediction)

### Specific files

frontend.py - client facing FPGA api

backend.py - hardware generation scripts

hw_strings.py - constant strings for kernel

host.cpp - data interface

xgboost.cpp - auto-generated kernel

### Results

Classification works for smaller models, with limited trees/estimators. There is an error where classifiers with unrestricted trees produce  different results than the software for a small number of inputs. Not sure why.

<!---### Links-->
