// backtracking (described in the book)
#include <bits/stdc++.h>

using namespace std;
vector<int> nums;
vector<vector<int>> answers;

void search(int cur_idx, vector<int> cur_set){
  if (cur_idx == nums.size()) {
    answers.push_back(cur_set);
  } else {
      search(cur_idx+1, cur_set);
      cur_set.push_back(nums[cur_idx]);
      search(cur_idx+1, cur_set);
      cur_set.pop_back();
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