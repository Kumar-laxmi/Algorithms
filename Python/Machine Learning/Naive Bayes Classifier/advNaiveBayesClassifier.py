import numpy as np


class NaiveBayesClassifier:
    def __init__(self):
        self.featureList = []  # vector to store features
        self.dataRecords = {}  # dictionary to store data records of the data set
        self.classifxnProbilty = {}  # store probabilities of classifications
        self.classifxnCount = {}  # map to store count of each classification in classifying feature
        self.testDataRes = {}  # store conditional probabilities outcomes for each classifxn value
        self.testData = []  # vector to store test data record
        self.numFeatures = 0
        self.numData = 0

    def displayDataSet(self):
        print("\nData Set:")
        # display all features
        for s in self.featureList:
            print(s, end="\t")

        for key, val in self.dataRecords.items():
            print("\n", key, end="\t")
            for s in val:
                print(s, end="\t")

    def countClassification(self, val):
        classifxn = []  # local list to store each classification from classifying feature

        # insert each classification into the vector
        for k, v in self.dataRecords.items():
            classifxn.append(v[self.numFeatures - 1])

        # calculate count of classification
        x = np.count_nonzero(np.array(classifxn) == val)

        # store count of this classifxn with its occurrence into classifxnCount dictionary
        self.classifxnCount[val] = x

        return x  # return the count

    def naiveClassifier(self):
        uniqueClassifxnFeat = np.unique([v[self.numFeatures - 1] for k, v in self.dataRecords.items()])
        maxProbilty = 0  # maximum probability

        # get no. of classifications
        numClassifxn = len(uniqueClassifxnFeat)

        # find probabilities of each classification in classifying feature
        for i in uniqueClassifxnFeat:
            # calculate probability of ith classification
            problilty = self.countClassification(i) / self.numData
            # insert this probability into the probability dictionary
            self.classifxnProbilty[i] = problilty

        # finding conditional probabilities of each value in test data w.r.t each classification
        for i in range(numClassifxn):
            # set probability 0 for each iteration
            problilty = 0
            # get count of matching classifications
            for j in range(len(self.testData)):
                # set count 0 for each iteration
                count = 0
                for k, v in self.dataRecords.items():
                    # if jth data value matches test data value (sunny, rainy, ...)
                    if v[j] == self.testData[j]:
                        # jth data classifixn matches ith classifxn value (yes, no, ...)
                        if v[self.numFeatures - 1] == uniqueClassifxnFeat[i]:
                            count += 1  # increment count

                # calculate conditional probability of ith classifxn value
                problilty += count / self.classifxnCount[uniqueClassifxnFeat[i]]

            # insert the result into result map after multiplying with ith classifxn value's probability
            self.testDataRes[uniqueClassifxnFeat[i]] = problilty * self.classifxnProbilty[uniqueClassifxnFeat[i]]

        # find classifxn value with maximum probability
        maxProbilty = max(self.testDataRes.values())
        classifiedRes = [k for k, v in self.testDataRes.items if v == maxProbilty()]
            # display final classification results
        print("\n\nCLASSIFIED RESULT:", classifiedRes)

def main(self):
    print("\n\t==== NAIVE BAYES CLASSIFIER ====")

    self.numFeatures = int(input("\nEnter the number of Features: "))
    self.numData = int(input("Enter the number of Data Records: "))

    # input feature list
    print("Enter all", self.numFeatures, "Features (last feature being the classifying feature):")
    inpStr = input()
    self.featureList = inpStr.split()

    # input all data records w.r.t each feature
    print("\nEnter the data for each record in format:")
    print("\t", end="")
    # display all features
    for s in self.featureList:
        print(s, end="\t")
    print()

    for i in range(self.numData):
        print(i, ":", end=" ")
        inpStr = input()
        # insert data into the dictionary
        for j, val in enumerate(inpStr.split()):
            if j not in self.dataRecords:
                self.dataRecords[j] = []
            self.dataRecords[j].append(val)

    # input the test data to be classified
    print("\nEnter the test data to be classified (same format):")
    inpStr = input()
    self.testData = inpStr.split()

    self.displayDataSet()  # function call to display the data set
    self.naiveClassifier()  # function call for naive classifier algorithm
