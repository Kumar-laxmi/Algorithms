# **Linear Regression**

This script implements multiple linear regression using a closed-form solution
to find optimal fit. User can analyze a dataset of their choice by providing:

1. relative path to their CSV file
2. name of the target column  

If these are not provided, a demo dataset included with the script is used.
For datasets with two or less independent variables, there is an option to
visualize the fit of the regression model.

Python version: 3.10.8

External packages:

1. pandas
2. numpy
3. matplotlib

References

1. [Closed form solution for linear regression](http://www.dsplog.com/2011/12/04/closed-form-solution-linear-regression/)
2. [Simple Linear Regression: A Practical Implementation in Python](https://www.askpython.com/python/examples/linear-regression-in-python)
3. [Argparse documentation](https://docs.python.org/3.10/library/argparse.html)

## Usage

* Create a virtual environment and install the dependencies specified in requirements.txt
* Navigate to the Linear_Regression folder in the terminal.
* Understand the usage of the script using the command:

```python
    python linear_regression.py -h
```

* For the demo version, run the script without any arguments:

```python
    python linear_regression.py
```

(Demo dataset is self-generated using the *random* module from *numpy* package)

* To provide your own dataset (as a CSV file):

```python
    python linear_regression.py <PATH_TO_CSV_FILE> <TARGET_NAME>
```

e.g.

```python
    python linear_regression.py demo_dataset.csv DV
```

(Path and target for demo version is specified explicitly to show usage)
