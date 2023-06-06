# Logistic Regression

This script implements logistic regression trained via gradient descent algorithm, to perform binary classification.  

User can analyze a dataset of their choice by providing the relative path to their CSV file.  
Model training can also be customized by providing the number of iterations for running gradient descent,  
and the learning rate to determine the shrinkage factor for updating model parameters in each iteration.  

If these are not provided, a demo dataset included with the script is used.  
Default number of iterations and learning rate are also defined for demonstration.

Python version: 3.10.8

External packages:
1. pandas  
2. numpy


**Script usage can also be understood via the command line:**    

```bash    
python logistic_regression.py -h
```
![output0](https://user-images.githubusercontent.com/107040862/213174826-6d19aa6d-ddf6-438f-91f3-ab4de013c0a4.png)

**Demo run:**
```bash
python logistic_regression.py
```
![output1](https://user-images.githubusercontent.com/107040862/213175289-c80a45bb-935b-4605-addf-0541de6dc2ce.png)

**Custom dataset:**
```bash
python logistic_regression.py <string-RELATIVE_PATH_TO_CSV_FILE>
```
![output2](https://user-images.githubusercontent.com/107040862/213175647-112fcc8e-7193-47c9-9307-82ef799baebd.png)

**Custom dataset with specific number of iterations and learning rate:**
```bash
python logistic_regression.py <string-RELATIVE_PATH_TO_CSV_FILE> <int-NUMBER_OF_ITERATIONS> <float-LEARNING_RATE>
```
![output3](https://user-images.githubusercontent.com/107040862/213176186-b1bc102e-2ced-42b0-8ae0-2c61a39f1422.png)
