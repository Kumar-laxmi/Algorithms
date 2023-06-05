/*

👉 Naïve Bayes Classifier is a supervised learning algorithm based on Bayes theorem and used for solving classification problems.

👉 It is called Naïve because it assumes that the occurrence of a certain feature is independent of the occurrence of other features.

STEPS
=====
⇒ Find probabilities of each classification from the classifying feature.
⇒ Find conditial probabilities of each value in test data w.r.t each classification.
⇒ Compare the probabilities of each classification and classify the test data to the classification with maximum probability.

*/

#include <iostream>  // basic input output
#include <string>    // string related function
#include <sstream>   // stream related function
#include <map>       // key value pairs of data records and probabilities
#include <vector>    // dynamic array to store feature list and test data records
#include <algorithm> // count() -> count occurence of a character in a data structure
                     // sort() -> sort the elements in a data structure
                     // unique() -> remove duplicate elements from a data structure

using namespace std;

int numFeatures, numData;              // no. of features & data records
vector<string> featureList;            // vector to store features
map<int, vector<string>> dataRecords;  // map to store data records of the data set
map<string, double> classifxnProbilty; // store probabilities of classifications
map<string, int> classifxnCount;       // map to store count of each classification in classifying feature
map<string, double> testDataRes;       // store conditional probabilities outcomes for each classifxn value
vector<string> uniqueClassifxnFeat;    // vector of unique classifying feature
vector<string> testData;               // vector to store test data record

// function to display the data set
void displayDataSet()
{
    cout << "\nData Set :\n\t";
    // display all features
    for (string s : featureList)
        cout << s << "\t";

    for (auto i : dataRecords)
    {
        cout << endl
             << i.first << "\t";
        for (string s : i.second)
            cout << s << "\t";
    }
}

// function to get count of classification from the data set
int countClassification(string value)
{
    int x;                    // count to be returned
    vector<string> classifxn; // local vector to store each classification from classifying feature

    // insert each classification into the vector
    for (auto i : dataRecords)
        classifxn.push_back(i.second[numFeatures - 1]);

    // calculate count of classification
    x = count(classifxn.begin(), classifxn.end(), value);

    // store count of this classifxn with its occurence into classifxnCount map
    classifxnCount.insert({value, x});
    // return the count
    return x;
}

// function for implementing Naive Classifier
void naiveClassifier()
{
    int numClassifxn; // number of classifications
    // finding unique classifying features
    int count;                 // store count of classification match while finding conditional probabilities
    int maxProbilty = 0; // maximum probability
    double probilty;           // store calculated probability
    string classifiedRes;      // store classified result of Naive Bayes Classifier

    // insert each value from classifying feature into vector
    for (auto i : dataRecords)
        uniqueClassifxnFeat.push_back(i.second[numFeatures - 1]);

    // delete duplicates from uniqeClassifxnFeat vector
    // sort vector to put all duplicates in the end
    sort(uniqueClassifxnFeat.begin(), uniqueClassifxnFeat.end());
    // delete all duplicates from starting to end
    uniqueClassifxnFeat.erase(unique(uniqueClassifxnFeat.begin(), uniqueClassifxnFeat.end()), uniqueClassifxnFeat.end());

    // get no. of classifications
    numClassifxn = uniqueClassifxnFeat.size();

    // find probabilities of each classification in classifying feature
    for (int i = 0; i < numClassifxn; i++)
    {
        // calculate probability of ith classification
        probilty = countClassification(uniqueClassifxnFeat[i]) / numData;
        // insert this probilty into the probilty map
        classifxnProbilty.insert({uniqueClassifxnFeat[i], probilty});
    }

    // finding conditial probabilities of each value in test data w.r.t each classification
    for (int i = 0; i < numClassifxn; i++)
    {
        // set probilty 0 for each iteration
        probilty = 0;
        // get count of matching classifications
        for (int j = 0; j < testData.size(); j++)
        {
            // set count 0 for each iteration
            count = 0;
            for (auto k : dataRecords)
            {
                // if jth data value matches test data value (sunny, rainy, ...)
                if (k.second[j] == testData[j])
                {
                    // jth data classifixn matches ith classifxn value (yes, no, ...)
                    if (k.second[numFeatures - 1] == uniqueClassifxnFeat[i])
                        ++count; // increment count
                }
            }
            // calculate conditional probability of ith classifxn value
            probilty += count / classifxnCount[uniqueClassifxnFeat[i]];
        }

        // insert the result into result map after multiplying with ith classifxn value's probability
        testDataRes.insert({uniqueClassifxnFeat[i], probilty * classifxnProbilty[uniqueClassifxnFeat[i]]});
    }

    // find classifxn value with maximum probability
    for (auto i : testDataRes)
    {
        if (i.second > maxProbilty)
        {
            maxProbilty = i.second;
            classifiedRes = i.first;
        }
    }

    // display final classification results
    cout << "\n\nCLASSIFIED RESULT : " << classifiedRes;
}

int main()
{
    string str; // input string

    cout << "\n\t==== NAIVE BAYES CLASSIFIER ====";

    cout << "\nEnter the no. of Features : ";
    cin >> numFeatures;

    cout << "\nEnter the number of Data Records : ";
    cin >> numData;

    // input feature list
    cout << "\nEnter all " << numFeatures << " Features (last feature being the classifying feature) :\n";
    for (int i = 1; i <= numFeatures; i++)
    {
        cin >> str;
        featureList.push_back(str);
    }

    // input all data records w.r.t each feature
    cout << "\nEnter the data for each record in format :\n\t";
    // display all features
    for (string s : featureList)
        cout << s << "\t";
    cout << endl;
    for (int i = 0; i < numData; i++)
    {
        cout << i << " : ";
        getline(cin, str);
        stringstream ss(str); // stringstream object to read from input string
        // insert data into the map
        while (ss >> str)
            dataRecords[i + 1].push_back(str);
    }

    // input the test data to be classified
    cout << "\nEnter the test data to be classified (same format) :\n";
    for (int i = 0; i < numFeatures - 1; i++)
    {
        cin >> str;
        testData.push_back(str);
    }

    displayDataSet(); // function call to display the data set

    naiveClassifier(); // function call for naive classifier algorithm

    return 0;
}