/*

👉 A Feed Forward Neural Network is an artificial neural network in which the connections between nodes does not form a cycle.

👉 The feed forward model is the simplest form of neural network as information is only processed in one direction.

STEPS
=====
⇒ Input details of all nodes.
⇒ Find feed value of each node by adding its bias value to sum of product of edgeweight and nodal value.
⇒ Pass the feed value into sigmoid function to get the final nodal value.
⇒ Repeat this process until last node of the neural network (NN).
⇒ Classify the result based on the maximum nodal value out of all nodes in the output layer.

*/

#include <iostream> // for general input output statements
#include <vector>   // for vector -> a dynamic array
#include <map>      // for map data structure
#include <math.h>   // for pow() -> calculate exponential power
#include <cmath>    // for exp() -> euler's constant function

using namespace std;

// global variable declarations
int nodeCount, hiddenLayerCount, inputNodes, linkNums, n; // n -> input variable for connected node's no.

// Node class definition
class Node
{
public:
    int num;                            // node number
    double bias;                        // added bias on the node
    double nodeValue;                   // calculated node value through function (sigmoid or linear)
    bool isOuputNode = false;           // for output node
    vector<int> links;                  // dynamic array for links with other nodes
    map<pair<int, int>, double> edgeWt; // map for edge weights between all nodes (key-value pair)

    // function to set edge weights of all nodes linked with current node
    void setEdgeWt()
    {
        double wt;
        for (int i = 0; i < links.size(); i++)
        {
            cout << "\nEdge Wt. " << num << " -> " << links[i] << " : ";
            cin >> wt;                            // input weight
            edgeWt.insert({{num, links[i]}, wt}); // insert into map
        }
    }
};

// function to input a layer details
void getLayerDetails(Node *nodes, bool isHiddenLayer = false, bool isOutputLayer = false)
{
    cout << "\nEnter no. of nodes in this layer : ";
    cin >> inputNodes; // get no. of nodes in current layer

    for (int i = 0; i < inputNodes; i++)
    {
        cout << "\nEnter node no. : ";
        cin >> nodes[i].num; // get unique node number
        cout << "\nEnter bias : ";
        cin >> nodes[i].bias; // get node bias

        // if current node is in input layer
        if (!isHiddenLayer and !isOutputLayer)
        {
            cout << "\nEnter node value : ";
            cin >> nodes[i].nodeValue; // get node value
        }

        if (!isOutputLayer)
        {
            cout << "\nEnter no. of links to other nodes : ";
            cin >> linkNums;
            cout << "\nEnter node no.s for connected " << linkNums << " nodes : ";
            // input connections to other unique nodes
            for (int j = 0; j < linkNums; j++)
            {
                cin >> n;
                nodes[i].links.push_back(n);
            }
            // input edge weights
            cout << "\nEnter edge weights :\n";
            nodes[i].setEdgeWt(); // function call to set edge weights for current node
        }

        cout << "\n\t!!! NODE DETAILS SAVED !!!\n";
    }
}

// function to calculate feed value of a node
double feedValue(Node *node, int n)
{
    double x = node[n].bias; // feed value variable
    for (auto i : node[n].edgeWt)
    { // traverse through edge-weight map of current node
        // if current node's number found in the map
        if (node[n].num == i.first.second)
        {
            // traverse through all nodes
            for (int j = 0; j < nodeCount; j++)
            {
                // if a node is connected to current node
                if (node[j].num == i.first.first)
                    // add product of node value and branch weight into feed value
                    x += node[j].nodeValue * i.second;
            }
        }
    }
    return x; // return feed value of this node
}

// neural network using sigmoid function
void sigmoidFunction(Node *nodes)
{
    double maxNodeVal = 0, tempVal; // for maximum node value in NN
    int maxOpNode, classifiedClass; // max node value number and its class
    string classRes = "";           // for output node that

    // calculate function value for each node in NN
    for (int i = 0; i < nodeCount; i++)
        nodes[i].nodeValue = 1 / (1 + exp(-1 * feedValue(nodes, i)));

    // find maximum node value in NN
    for (int i = nodeCount; i >= inputNodes; i--)
    {
        if (nodes[i].isOuputNode == true)
        {
            tempVal = nodes[i].nodeValue;
            // compare current output node with maximum node value
            if (tempVal >= maxNodeVal)
            {
                maxNodeVal = tempVal;
                maxOpNode = i;
            }
        }
    }

    // output maximum node value, node number and classification result
    cout << "\n\t!!! NN OUTPUT !!!";
    cout << "\nMaximum node value : " << maxNodeVal;
    cout << "\nNode Number : " << maxOpNode;
}

// main function
int main()
{
    cout << "\n\t=== FEED FORWARD NEURAL NETWORK ===" << endl;

    // input the neural network details
    cout << "\nEnter total no. of nodes in the NN : ";
    cin >> nodeCount;
    cout << "\nEnter no. of hidden layers : ";
    cin >> hiddenLayerCount;

    Node nodes[nodeCount]; // array of nodes

    // input layer details
    cout << "\n\tINPUT LAYER DETAILS :";
    getLayerDetails(nodes); // function call to get input layer details

    // hidden layer details
    cout << "\n\tHIDDEN NODE DETAILS :";
    for (int i = 0; i < hiddenLayerCount; i++)
    {
        cout << "\nHIDDEN LAYER " << i + 1 << " :";
        getLayerDetails(nodes, true); // function call to get hidden layer details
    }

    // output layer details
    cout << "\n\tOUTPUT LAYER DETAILS :";
    getLayerDetails(nodes, false, true); // function call to get output layer details

    sigmoidFunction(nodes); // function call for sigmoid function implementation

    return 0;
}
