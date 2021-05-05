from sklearn.datasets import load_iris
import xgboost
import backend as bk

#load data
X, y = load_iris(return_X_y=True)

#train model
#model = xgboost.XGBRegressor()   // on the to do list, similar hardware to classifier
model = xgboost.XGBClassifier(max_depth=2, n_estimators=1, use_label_encoder=False)
#model = xgboost.XGBClassifier(use_label_encoder=False)
model.fit(X, y, eval_metric='logloss');

#generate hardware
bk.generate_classification_hardware(model)

#print X and predict(X) to file
bk.export_inputs_and_outputs(X, model.predict(X))
