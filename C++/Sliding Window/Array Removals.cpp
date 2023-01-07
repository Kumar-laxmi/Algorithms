Question:- You’re given an array ‘ARR’ of size N and an integer K.
Task is to determine the minimum number of elements that should be removed from the array such that 
the difference between the maximum and the minimum element in the remaining array is less than or equal to K.
  
class Solution{
    public:
    int removals(vector<int>& arr, int k){
       //sliding window
        sort(arr.begin() , arr.end());

        int maxwindow = 0;
        int i =0 , j=0;

        while(j<arr.size()){
            if(arr[j] - arr[i] <=k){
                j++;
            }

            else if(i< j){
                i++;
            }

            maxwindow= max(maxwindow, j-i);
        }
        return (arr.size() - maxwindow);
    }
};
