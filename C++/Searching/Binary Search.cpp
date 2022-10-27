
#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
        int  start = 0;
        int end = nums.size()-1;
        while(start<=end)
        {
             int mid = start + (end - start) / 2;
             if(nums[mid] == target) return mid;
             else if(nums[mid] > target) end = mid-1;
            else start = mid+1;
        }
        return -1;    
    }
void display_result(int foundAt)
{
  if(foundAt != -1) cout<<"Found at index "<<foundAt<<endl;
  else cout<<"Oops! Not found :-("<<endl;
}
int main() 
{
  vector<int> nums = {-1,0,3,5,9,12};
  display_result(search(nums , 9));
  display_result(search(nums , 99));
  return 0;
}
