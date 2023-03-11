/*

👉 K-Means Clustering is an unsupervised learning algorithm that is used to solve the clustering problems in machine learning or data science.

👉 It groups the unlabeled dataset intp different clusters.

STEPS
=====
⇒ Initialize first k clusters.
⇒ Find distance of each data point from these k clusters, using Manhattan Distance Formula
⇒ Assign each point to the respective cluster based on their shortest distance from the cluster points.

*/

#include <iostream>  // basic input output streams
#include <vector>    // dynamic array
#include <algorithm> // find() -> find occurence of an element in a data structure
                     // *min_element() -> find minimum element in a data structure
#include <map>

using namespace std;

pair<int, int> clusterPt1, clusterPt2, clusterPt3; // initial cluster points
vector<char> initCluster;                          // dynamic array of initial cluster points' names
vector<double> pointDist;                          // dynamic array of distances between points
vector<char> coordName;                            // dynamic array of coordinate names
vector<char> cluster1, cluster2, cluster3;         // dynamic array for classified cluster points
map<int, pair<int, int>> clusterPtDist;            // a map for distances b/w clusters and points
int k = 3;                                         // k - value

class Coordinate
{
public:
    char coordName;       // coordinate name
    pair<int, int> coord; // coordinates
};

int getDistance(Coordinate *coord, pair<int, int> clusterPt, int x)
{
    int dist = abs(coord[x].coord.first - clusterPt.first) + abs(coord[x].coord.second - clusterPt.second);

    clusterPtDist.insert({dist, {clusterPt.first, clusterPt.second}}); // insert distance along with cluster

    return dist;
}

void clusteringAlgo(Coordinate *coord, int n)
{
    int minDist;

    // set initial cluster points
    for (int i = 0, j = 0; i < n; i++)
    {
        if (coord[i].coordName == initCluster[j])
        {
            ++j;
            clusterPt1.first = coord[i].coord.first;
            clusterPt1.second = coord[i].coord.second;
        }
    }

    for (int i = 0; i < n - k; i++)
    {
        if (find(initCluster.begin(), initCluster.end(), coord[i].coordName) == initCluster.end())
        {

            // find distance of ith point from the k clusters
            for (int j = 0; j < k; j++)
            {
                pointDist.push_back(getDistance(coord, clusterPt1, i));
                pointDist.push_back(getDistance(coord, clusterPt2, i));
                pointDist.push_back(getDistance(coord, clusterPt3, i));
            }

            // find closest cluster from ith point
            minDist = *min_element(pointDist.begin(), pointDist.end());

            for (auto k : clusterPtDist)
            {
                // update closest cluster point
                if (minDist == k.first)
                {
                    // first cluster closest to current data point
                    if (k.second.first == clusterPt1.first and k.second.second == clusterPt2.second)
                    {
                        // update cluster map with new classified point
                        cluster1.push_back(coord[i].coordName);

                        // update closest cluster point
                        clusterPt1.first = (clusterPt1.first + coord[i].coord.first) / 2;
                        clusterPt1.second = (clusterPt1.second + coord[i].coord.second) / 2;
                    }

                    // second cluster closest to current data point
                    else if (k.second.first == clusterPt2.first and k.second.second == clusterPt2.second)
                    {
                        // update cluster map with new classified point
                        cluster2.push_back(coord[i].coordName);

                        // update closest cluster point
                        clusterPt2.first = (clusterPt2.first + coord[i].coord.first) / 2;
                        clusterPt2.second = (clusterPt2.second + coord[i].coord.second) / 2;
                    }

                    // third cluster closest to current data point
                    else if (k.second.first == clusterPt3.first and k.second.second == clusterPt3.second)
                    {
                        // update cluster map with new classified point
                        cluster3.push_back(coord[i].coordName);

                        // update closest cluster point
                        clusterPt3.first = (clusterPt3.first + coord[i].coord.first) / 2;
                        clusterPt3.second = (clusterPt3.second + coord[i].coord.second) / 2;
                    }
                }
                coordName.clear(); // clear coordinate name's vector for next iteration
            }
        }
        pointDist.clear(); // clear point distance vector for next iteration
    }
}

// function to show clusters with classified points
void showClusters()
{
    cout << "Classified Data Points :\n";
    cout << "Cluster 1 : ";
    for (char c : cluster1)
        cout << c << " ";
    cout << "\nCluster 2 : ";
    for (char c : cluster2)
        cout << c << " ";
    cout << "\nCluster 3 : ";
    for (char c : cluster3)
        cout << c << " ";
}

// main function definition
int main()
{
    int n;   // number of data points
    char ch; // choice holding variable

    cout << "\n\t=== K MEANS CLUSTER ===";

    // input data points
    cout << "\nEnter no. of data points : ";
    cin >> n;

    Coordinate cltr[n]; // make n no. of coordinate points

    cout << "Enter data points (coordName x y) : ";
    for (int i = 0; i < n; i++)
        cin >> cltr[i].coordName >> cltr[i].coord.first >> cltr[i].coord.second;

    // choose initial cluster points
    cout << "Choose 3 clusters point among the following :\n";
    for (int i = 0; i < n; i++)
        cout << cltr[i].coordName << ". (" << cltr[i].coord.first << ", " << cltr[i].coord.second << ")" << endl;

    cout << "\nMAKE YOUR CHOICES : ";
    for (int i = 0; i < k; i++)
    {
        cin >> ch;
        initCluster.push_back(ch);
    }

    clusteringAlgo(cltr, n); // function call to classify the data points in clusters

    showClusters(); // function call to display clusters with classified data points

    return 0;
}