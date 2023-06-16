# 👉 Naïve Bayes Classifier is a supervised learning algorithm based on Bayes theorem and used for solving classification problems.

# 👉 It is called Naïve because it assumes that the occurrence of a certain feature is independent of the occurrence of other features.

# STEPS
# =====
# ⇒ Find probabilities of each classification from the classifying feature.
# ⇒ Find conditial probabilities of each value in test data w.r.t each classification.
# ⇒ Compare the probabilities of each classification and classify the test data to the classification with maximum probability.

featureList = []  # vector to store features
dataRecords = {}  # dictionary to store data records of the data set
classifxnProbilty = {}  # store probabilities of classifications
classifxnCount = {}  # map to store count of each classification in classifying feature
testDataRes = {}  # store conditional probabilities outcomes for each classifxn value
testData = []  # vector to store test data record


# function to display the data set
def displayDataSet():
    print("\nData Set :")
    # display all features
    for s in featureList:
        print(s, end="\t")

    for key, val in dataRecords.items():
        print("\n", key, end="\t")
        for s in val:
            print(s, end="\t")


# function to get count of classification from the data set
def countClassification(val):
    classifxn = []  # local list to store each classification from classifying feature

    # insert each classification into the vector
    for k, v in dataRecords.items():
        classifxn.append(v[numFeatures - 1])

    # calculate count of classification
    x = classifxn.count(val)

    # store count of this classifxn with its occurence into classifxnCount dictionary
    classifxnCount[val] = x

    return x  # return the count


# function for implementing Naive Classifier
def naiveClassifier():
    uniqueClassifxnFeat = []  # vector of unique classifying feature
    maxProbilty = 0  # maximum probability

    # insert each value from classifying feature into vector
    for k, v in dataRecords.items():
        uniqueClassifxnFeat.append(v[numFeatures - 1])

    # delete duplicates from uniqeClassifxnFeat list
    uniqueClassifxnFeat = list(set(uniqueClassifxnFeat))

    # get no. of classifications
    numClassifxn = len(uniqueClassifxnFeat)

    # find probabilities of each classification in classifying feature
    for i in uniqueClassifxnFeat:
        # calculate probability of ith classification
        problilty = countClassification(i) / numData
        # insert this probilty into the probilty dictionary
        classifxnProbilty[i] = problilty

    # finding conditial probabilities of each value in test data w.r.t each classification
    for i in range(numClassifxn):
        # set probilty 0 for each iteration
        problilty = 0
        # get count of matching classifications
        for j in range(len(testData)):
            # set count 0 for each iteration
            count = 0
            for k, v in dataRecords.items():
                # if jth data value matches test data value (sunny, rainy, ...)
                if v[j] == testData[j]:
                    # jth data classifixn matches ith classifxn value (yes, no, ...)
                    if v[numFeatures - 1] == uniqueClassifxnFeat[i]:
                        count += 1  # increment count

            # calculate conditional probability of ith classifxn value
            problilty += count / classifxnCount[uniqueClassifxnFeat[i]]

        # insert the result into result map after multiplying with ith classifxn value's probability
        testDataRes[uniqueClassifxnFeat[i]] = problilty * \
            classifxnProbilty[uniqueClassifxnFeat[i]]

    # find classifxn value with maximum probability
    for k, v in testDataRes.items():
        if v >= maxProbilty:
            maxProbilty = v
            classifiedRes = k

    # display final classification results
    print("\n\nCLASSIFIED RESULT :", classifiedRes)


def main():
    # no. of features & data records
    global numFeatures, numData

    print("\n\t==== NAIVE BAYES CLASSIFIER ====")

    numFeatures = int(input("nEnter the no. of Features : "))

    numData = int(input("Enter the number of Data Records : "))

    # input feature list
    print("Enter all", numFeatures,
          "Features (last feature being the classifying feature) :")
    inpStr = input()
    featureList = inpStr.split()

    # input all data records w.r.t each feature
    print("\nEnter the data for each record in format :", end="\n\t")
    # display all features
    for s in featureList:
        print(s, end="\t")
    print()
    for i in range(numData):
        print(i, ":", end=" ")
        inpStr = input()
        # insert data into the dictionary
        for j in inpStr:
            dataRecords[i] = inpStr.split()

    # input the test data to be classified
    print("\nEnter the test data to be classified (same format) :")
    inpStr = input()
    testData = inpStr.split()

    displayDataSet()  # funct ion call to display the data set

    naiveClassifier()  # function call for naive classifier algorithm


main()
