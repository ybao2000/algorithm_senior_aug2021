#include <bits/stdc++.h>

using namespace std;
vector<int> nums;
vector<vector<int>> answers;
int N;
void search() {
  // loop through 2^N (using left shift)
  for(int i=0; i<(1<<N); i++){
    vector<int> answer;
    for(int j=0; j<N; j++) {
      if ((i & (1<<j)) != 0){ // check index of j
        answer.push_back(nums[j]);
      }
    }
    answers.push_back(answer);
  }
}

int main() {
  cin >> N;
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    nums.push_back(x);
  }
  sort(nums.begin(), nums.end());
  vector<int> empty_set;
  search();
  for(auto it : answers){
    for (auto x: it) {
      cout << x << " ";
    }
    cout << "\n";
  }  
}