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
* Understand the usage of the script:

```python
    python linear_regression.py -h
```
![help_output](https://user-images.githubusercontent.com/107040862/211871781-65699b4f-5523-4250-ab71-ffc46760d14f.png)

* For the demo version, run the script without any arguments:
(Demo dataset is self-generated using the *random* module from *numpy* package)

```python
    python linear_regression.py
```
![demo2](https://user-images.githubusercontent.com/107040862/211871932-d254aee8-2e50-402a-9448-5674c9ff0adb.png)
![output_2d](https://user-images.githubusercontent.com/107040862/211872537-510225ee-9d10-4545-bbe2-0db93dac52e2.png)

* To provide your own dataset (as a CSV file):

```python
    python linear_regression.py <PATH_TO_CSV_FILE> <TARGET_NAME>
```
![demo3](https://user-images.githubusercontent.com/107040862/211872185-b31aa267-49b6-4240-84fb-dffb100ef7a7.png)
![output_3d](https://user-images.githubusercontent.com/107040862/211872601-4951c306-db9a-4687-ac14-bd65e8912a4d.png)

* Visualization can also be skipped:
![demo4](https://user-images.githubusercontent.com/107040862/211872466-0f27d945-5222-41f1-accb-aa392b685f36.png)
