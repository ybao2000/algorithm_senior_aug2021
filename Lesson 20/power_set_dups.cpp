// backtracking
#include <bits/stdc++.h>

using namespace std;
vector<int> nums;
vector<vector<int>> answers;

void search(int cur_idx, vector<int> cur_set){
  vector<int> set2 = cur_set;
  answers.push_back(set2);
  for(int i=cur_idx; i<nums.size(); i++){
    // add condition here!!!
    if (i > cur_idx && nums[i] == nums[i-1]) continue;  // skip the same number
    cur_set.push_back(nums[i]); // push back the element at i
    search(i+1, cur_set);
    cur_set.pop_back(); // recover to the original state
  }
}

int main() {
  int N;
  cin >> N;
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    nums.push_back(x);
  }
  sort(nums.begin(), nums.end());
  vector<int> empty_set;
  search(0, empty_set);
  for(auto it : answers){
    for (auto x: it) {
      cout << x << " ";
    }
    cout << "\n";
  }
}