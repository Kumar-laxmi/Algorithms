#include <bits/stdc++.h>
using namespace std;
// Kadane Algorithm is used to find Largest Sum Contiguous Subarray
// It works in O(N) Time Complexity and O(1) Space Complexity
class Kadane
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // this variable is used to capture the sum at each iteration
        int sum = 0;
        // this is used to store the maximum sum received in each iteration
        int maxi = 0;
        // Travelling the whole array
        for (int i = 0; i < nums.size(); i++)
        {
            // Adding current element to the sum
            sum = sum + nums[i];
            // comparing it with the max sum till now
            maxi = max(maxi, sum);
            // if the sum becomes negative then there is no point in moving forward with that subarray so updated sum=0 for next iterations
            if (sum < 0)
            {
                sum = 0;
            }
        }
        // returning the max sum
        return maxi;
    }
};
int main()
{
    // size of the array
    int n;
    cout << "Enter the size of the Array :";
    cin >> n;
    // created the vector
    vector<int> v;
    // storing the elements
    cout << "Enter the Elements :";
    while (n--)
    {
        // taking input from the user
        int element;
        cin >> element;
        v.push_back(element);
    }
    // creating the object of the class
    Kadane obj;
    // storing the max_sub_array sum
    int max_subarray_sum = obj.maxSubArray(v);
    // Printing the result
    cout << "Maximum Sub Array sum in :";
    for (auto i : v)
    {
        cout << i << "  ";
    }
    cout << "is: " << max_subarray_sum << endl;
    return 0;
}