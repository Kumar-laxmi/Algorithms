/*

▶ Logistic Regression is a machine learning algorithm that estimates the probability of an event occurring, based on a given dataset of independent variables. The output of dependent variable is between 0 and 1.

▶ The function used in Logistic Regression is Sigmoid Function :
    y = 1 / (1 + e^z)
    y → Dependent feature
    e → Eular's Constant
    z → Linear function of single variable x, z = mx + c
    m → Line Slope
    c → Line Intercept

Steps
=====
⇒ Find mean of independent feature (x), xMean.
⇒ Find mean of dependent feature (y), yMean.
⇒ Find predicted line's slope (m), m = SUM[(x[i] - xMean)*(y[i] - yMean)] / SUM[(x[i] - xMean)].
⇒ Find predicted line's intercept (c), c = yMean - slope * xMean.
⇒ Use intercept and slope values in z to predict dependent feature value from sigmoid function.

*/

#include<iostream> // basic input output
#include<vector> // to store dataset in dynamic arrays (vectors)
#include<numeric> // for accumulate(), to find sum of vectors (dynamic arrays)
#include<cmath> // for sqrt(), to find square root used in slope calculation
using namespace std; // define standard namespace

// Predicted Line class
class PredLine {
public:
    float slope, intcpt, xMean, yMean; // class attributes
    float calcSlope(vector<int> , vector<int>); // member function to find line slope
} line;

float PredLine::calcSlope(vector<int> feat1, vector<int> feat2) {
    float slope, slopeNumerator = 0.0, slopeDenominator = 0.0;
    float f1Size = feat1.size(); // size of feature 1 vector

    // calculate numerator part in the slope formula
    for(int i = 0; i < f1Size; i++)
        slopeNumerator += (feat1[i] - line.xMean) * (feat2[i] - line.yMean);
    
    // calculate denominator part in the slope formula
    for(int i = 0; i < f1Size; i++)
        slopeDenominator += sqrt(feat1[i] - line.xMean);

    slope = slopeNumerator / slopeDenominator;
    return slope;
}

int main() {
    vector<int> feat1, feat2, classification; // dynamic arrays for dependent and independent features
    char ch = 'y'; // continue choice variable
    int n; // no. of records
    float ele, x, y; // feature element, line equation variables
    double res; // sigmoid function result
    
    cout << "======= LOGISTIC REGRESSION =======";

    while(ch == 'y') {
        cout << "\nEnter no. of records : ";
        cin >> n; // input no. of records
        
        // input data set
        cout << "\nEnter Independent Data (x1) : ";
        // input independent feature
        for(int i = 0; i < n; i++) { cin >> ele; feat1.push_back(ele); }
        cout << "\nEnter Dependent Data (x2) : ";
        // input dependent feature
        for(int i = 0; i < n; i++) { cin >> ele; feat2.push_back(ele); }
        // input classification        
        cout << "\nEnter Classification of each record (y) : ";
        // input dependent feature
        for(int i = 0; i < n; i++) { cin >> ele; classification.push_back(ele); }
        // input test data
        cout << "\nEnter Test Data (x1, x2) : "; cin >> x >> y;
        feat1.push_back(x); feat2.push_back(y);

        // find mean of x1 & x2 (both features)
        line.xMean = accumulate(feat1.begin(), feat1.end(), 0) / n;
        line.yMean = accumulate(feat2.begin(), feat2.end(), 0) / n;

        // find slope & intercept of predicted line
        line.slope = line.calcSlope(feat1, feat2);
        line.intcpt = line.yMean - line.slope * line.xMean;

        res = 1 / (1 + exp(line.slope * x + line.intcpt)); // sigmoid function implementation

        /* Result = 1   , if res > 0.5
                  = 0   , if res < 0.5
        */
        res > 0.5 ? cout << "\nPredicted Result : 1" : cout << "\nPredicted Result : 0";

        cout << "\nTry Again ? (y/n) : ";
        cin >> ch; // input choice to try again
    }
    return 0;
}