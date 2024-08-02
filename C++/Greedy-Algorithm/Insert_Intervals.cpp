/*
Name: Aryaman Singh
Repository name: Algorithms
S
Problem Statement: Given a sorted array of non-overlapping intervals where intervals[i]=[starti,endi] and a new interval=[start,end], insert the new interval 
into the array while maintaining the sort order and ensuring that there are no overlapping intervals. Return the updated array after the insertion.

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
*/

#include<iostream>
#include<vector>
using namespace std;

// Function for inserting the new interval
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    // new vector named ans that will store the final intervals after inserting
    vector<vector<int>> ans;
    int n = intervals.size();
     
    // it starts a loop that iterates over the intervals vector from index 0 to index n-1.
    for (int i = 0; i < n; i++)
    {
        // if the end of the current interval (intervals[i][1]) is less than the start of the new interval (newInterval[0]),it means there is no overlap, 
        // so the current interval is added to the ans vector.
        if (intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
        }

        //  if the start of the current interval (intervals[i][0]) is greater than the end of the new interval (newInterval[1]), it means there is no overlap, 
        // so the new interval is added to the ans vector, and the new interval is updated to the current interval.
        else if (intervals[i][0] > newInterval[1])
        {
            ans.push_back(newInterval);
            newInterval = intervals[i];
        }
        
        // if there is an overlap between the current interval and the new interval. It updates the start of the new interval to the minimum value 
        // between the current start and new start, and updates the end of the new interval to the maximum value between the current end and new end.
        else
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }

    // it adds the final merged interval (new interval) to the ans vector.
    ans.push_back(newInterval);
    return ans;
}

// Main function
int main(){
    vector<vector<int>> intervals= {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4,8};

    vector<vector<int>> final;
    final=insert(intervals,newInterval);

    for(auto it: final){
        cout<<"{"<<it[0]<<","<<it[1]<<"}"<<endl;
    }

    return 0;
}