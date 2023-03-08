import numpy as np
import pandas as pd
from matplotlib import pyplot as plt

#Boolean AND
#dataset = pd.DataFrame({'input1':[-1,-1,1,1],'input2':[-1,1,-1,1],'result':[-1,-1,-1,1]})
#Boolean OR
dataset = pd.DataFrame({'input1':[-1,-1,1,1],'input2':[-1,1,-1,1],'result':[-1,1,1,1]})

print("Dataset is: ")
print(dataset)

#activation function
def activation_function(x):
  #if x>=0 1 is returned
  if x>=0:
    return 1
  #if x<0 -1 is returned
  else:
    return -1

 
#perceptron starts its learning with some random weights.

class Perceptron:
  #defining a constructor
  def __init__(self,n,actFunc):
    self.actFunc = actFunc
    self.bias=0
    self.n=n
  #predict function to predict the weights in each iteration
  def predict(self,ls,w):
    sum=0
    k=0
    #print("Inputs are : ")
    for elem in range(0,len(ls)-1):
      #calculate sum 
      sum += w[k]*ls[elem]
      k=k+1
    s=sum+self.bias  #adding bias initially
    a = self.actFunc(s)
    return a
  def learnBoolean(self,data,learningRate,n): 
    
    w=[]  #list to store weights
    print("Initail random weights are : ")  
    #choose random weights initillay as iterations goes on adjust the rando weights to obtain the original weights
    for i in range(0,n):
      k=np.random.random()
      w.insert(i,k)
      print(w[i])
      #print(i,"th random value is : ",w[i])
    #initialised with random weights
    count=0
    while(True):
      val=True
      res=-1 
      #storing the result val 
      y = data["result"] 
      #traversing over the list
      for i,j in data.iterrows():
        count=count+1
        res=res+1
       # print("res is: ",res) 
        ls = j.tolist()          #convertinh the input to list
        a =self.predict(ls,w)    #calling a predict function
        #print("predicted value is: " ,a)
        #print("actual value is: ",y[res])
        #if guessed output is not same as predicted then tune the weights as per learning rate
        if a != y[res]:
          val=False
          for i in range(0,n):
            delw = (y[res]-a)*learningRate*ls[i]    #tuning the weights
            w[i]=w[i]+delw                          #Adding the delta w to w
            self.bias=learningRate*(y[res]-a)       #changing the bias according to learning rate
            #print("The value when",ls[i],"is: ",w[i],"and i is: ",i)
        #print("------------------------------")
      if val==True:
         break
    #print(count)
    print("SO Final output is: ")       #obtaining the final output
    for i in range(0,self.n):
      print(w[i])
    return count


#creating object for perceptron class

learningRate = float(input("ENter the learning rate: "))  #taking learniing rate as input from user
p = Perceptron(2,activation_function)  #creating a perceptron object
learn = p.learnBoolean(dataset,learningRate,2)  #calling a learnbollean function
print("The number of iterations it took for perceptron to learn is :  ",learn) #total iterations printing