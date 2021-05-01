## XGBoost inference

This proof of concept shows that I can take a specific xgboost model and run it through the FPGA. Uses the iris dataset.

Limited in that the model is predefined in the hardware (so I know where all the weights go).

Because we aren't testing model accuracy, the training data is fed through the FPGA (normally training/validation and test data are separate).

With classification trees (of n classes), each set of n trees produces the probability of that This is different from regression trees where the final result is the total sum of all tree results.

If we wanted to treat the individual class. tree results as a probability, we would have to apply the logistic function to the raw results. Fortunately, we only care about the largest probability, which is also the largest raw result because the logistic function is monotonic.


### Specific files

host.cpp - the cpp interface

xgboost.cpp - the HLS kernel 

frontend.py - client facing FPGA api

backend.py - data export scripts

data/xgb_model.txt - the model architecture I've coded for

data/extracted.data - the model's weights


### Results

The xgboost software predictions match the hardware predictions, so this first step is a success.


### Links

https://archive.ics.uci.edu/ml/datasets/Iris

https://medium.com/swlh/roll-your-own-xgboost-model-7490106b9523

https://xgboost.readthedocs.io/en/latest/tutorials/model.html

https://stackoverflow.com/questions/50175901/how-to-extract-decision-rules-features-splits-from-xgboost-model-in-python3
