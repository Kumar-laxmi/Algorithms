'''
Implementation of a Decision Tree using ID3 Algorithm.
Author - Anushka Nambiar
Requirements:
    - Numpy
    - Pandas
Python:
    - 3.10
Algorithm:
    1. Calculate the entropy of the whole dataset.
    2. Calculate the feature_entropy (entropy of each feature).
    3. Calculate the Information Gain of each attribute using it's corresponding feature_entropy.
    4. The attribute with the highest information gain will be the parent node.
    5. Continue 2, 3 and 4 till the decision tree is completed.
'''


import numpy as np
import pandas as pd

df = pd.read_csv('Algorithms/Python/Machine Learning/Decision Tree/PlayTennis.csv')

# Calculate the entropy for the whole dataset.
# Entropy(S) = -P(Yes)log2(P(Yes)) - P(No)log2(P(No)) 
def total_entropy(df, label, class_name):
    rows = df.shape[0]
    entropy = 0
    
    for i in class_name:
       class_count = df[df[label] == i].shape[0]
       class_entropy = -(class_count/rows)*np.log2(class_count/rows)
       entropy += class_entropy
       
    return entropy

# Calculate the entropy for each feature of an attribute
def feature_entropy(df, label, class_name):
    rows = df.shape[0]
    entropy = 0
    
    for i in class_name:
        label_count = df[df[label] == i].shape[0] 
        entropy_class = 0
        if label_count != 0:
            probability = label_count/rows 
            entropy_class = - probability * np.log2(probability)  
        entropy += entropy_class
    
    return entropy

# Calculate the information gain of an attribute.
# Information gain = Entropy(S) - Sum(Entropy(Feature)/Total No of Records)
def info_gain(feature_name, df, label, class_list):
    feature_value_list = df[feature_name].unique()
    row = df.shape[0]
    feature_info = 0.0
    
    for feature_value in feature_value_list:
        feature_value_data = df[df[feature_name] == feature_value] 
        feature_value_count = feature_value_data.shape[0]
        feature_value_entropy = feature_entropy(feature_value_data, label, class_list)
        feature_value_probability = feature_value_count/row
        feature_info += feature_value_probability * feature_value_entropy 
        
    return total_entropy(df, label, class_list) - feature_info

# Find the attribute the maximum information gain.
def max_infogain(data, label, class_list):
    feature_list = data.columns.drop(label) 
    max_info_gain = -1
    max_info = None
    
    for feature in feature_list: 
        feature_info_gain = info_gain(feature, data, label, class_list)
        if max_info_gain < feature_info_gain: 
            max_info_gain = feature_info_gain
            max_info = feature
            
    return max_info


# Generate the subtree after each step.
def sub_tree(feature_name, data, label, class_list):
    feature_value_count_dict = data[feature_name].value_counts(sort=False) 
    tree = {} 
    
    for feature_value, count in feature_value_count_dict.iteritems():
        feature_value_data = data[data[feature_name] == feature_value] 
        
        assigned_to_node = False 
        for c in class_list: 
            class_count = feature_value_data[feature_value_data[label] == c].shape[0] 

            if class_count == count:
                tree[feature_value] = c 
                data = data[data[feature_name] != feature_value] 
                assigned_to_node = True
        if not assigned_to_node: 
            tree[feature_value] = "?"
            
    return tree, data


# Design the decision tree.
def print_tree(root, prev_feature_value, data, label, class_list):
    if data.shape[0] != 0:
        max_info = max_infogain(data, label, class_list) 
        tree, data = sub_tree(max_info, data, label, class_list) 
        next_root = None
        
        if prev_feature_value != None:
            root[prev_feature_value] = dict()
            root[prev_feature_value][max_info] = tree
            next_root = root[prev_feature_value][max_info]
        else: 
            root[max_info] = tree
            next_root = root[max_info]
        
        for node, branch in list(next_root.items()):
            if branch == "?": 
                feature_value_data = data[data[max_info] == node] 
                print_tree(next_root, node, feature_value_data, label, class_list)
                
                
# The ID3 algorithm.
def id3(df, label):
    data = df.copy() 
    tree = {} 
    class_list = data[label].unique() 
    print_tree(tree, None, data, label, class_list) 
    print(tree)



tree = id3(df, 'play')