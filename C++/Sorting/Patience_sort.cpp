#include <bits/stdc++.h>
using namespace std;

vector<int> merge_piles(vector<vector<int> >& v) {
  vector<int> ans;
  while (1) {
    int min_v = INT_MAX;
    int index = -1;
    for (int i = 0; i < v.size(); i++) {
      if (min_v > v[i][v[i].size() - 1]) {
        min_v = v[i][v[i].size() - 1];
        index = i;
      }
    }
    ans.push_back(min_v);
    v[index].pop_back();
    if (v[index].empty()) {
      v.erase(v.begin() + index);
    }
    if (v.size() == 0)
      break;
  }
  return ans;
}

vector<int> patienceSorting(vector<int> arr) {
  vector<vector<int> > piles;
  for (int i = 0; i < arr.size(); i++) {
    if (piles.empty()) {
      vector<int> temp;
      temp.push_back(arr[i]);
      piles.push_back(temp);
    } else {
      int flag = 1;
      for (int j = 0; j < piles.size(); j++) {
        if (arr[i] < piles[j][piles[j].size() - 1]) {
          piles[j].push_back(arr[i]);
          flag = 0;
          break;
        }
      }

      if (flag) {
        vector<int> temp;
        temp.push_back(arr[i]);
        piles.push_back(temp);
      }
    }
  }

  vector<int> ans;
  ans = merge_piles(piles);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return ans;
}

int main() {
  vector<int> arr;
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;
  cout << "Enter the elements: ";
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << "Sorted Array: ";
  patienceSorting(arr);
  return 0;
}