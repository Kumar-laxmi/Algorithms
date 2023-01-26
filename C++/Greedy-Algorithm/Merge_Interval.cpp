/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
//Problem Statement : Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
//and return an array of the non-overlapping intervals that cover all the intervals in the input.
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// Initialise the interval
struct Intrvl
{
    int start, end;
    bool operator<(Intrvl const &i) 
    {
        return (start < i.start);
    }
};
// Function for merging the overlapping intervals
void IntervalMerge(vector<Intrvl> intervals)        // no-ref, no-const
{
    // sorting of intervals
    sort(intervals.begin(), intervals.end());
    // created an empty stack
    stack<Intrvl> s;
    // repeat this process for each interval
    for (const Intrvl &curr: intervals)
    {
        // if the stack is empty OR
        // if the top interval in the stack does not overlap with the current interval
        // push it into the stack
        if (s.empty() || curr.start > s.top().end) 
        {
            s.push(curr);
        }
        // and if the top interval of the stack overlaps with the current interval,
        // merge two intervals by updating the end of the top interval to the current interval
        if (s.top().end < curr.end) 
        {
            s.top().end = curr.end;
        }
    }
    while (!s.empty())
    {
        cout << '{' << s.top().start << ", " << s.top().end << "}\n";    // print all the non-overlapping intervals
        s.pop();
    }
} 
int main()    //Main Function
{
    vector<Intrvl> intervals = { { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } };
    IntervalMerge(intervals);
    return 0;
}