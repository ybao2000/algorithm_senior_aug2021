#include <bits/stdc++.h>

using namespace std;

void permute(vector<int> vi, vector<int> ans) {
  if(vi.size() == 0){
    for(int x : ans) {
      cout << x << " ";
    }
    cout << "\n";
    return;
  }
  for (int i=0; i<vi.size(); i++){
    int x = vi[i];
    vector<int> rest;
    for(int j=0; j<vi.size(); j++){
      if (j != i){
        rest.push_back(vi[j]);
      }
    }
    vector<int> new_ans = ans; // make a copy
    new_ans.push_back(x);
    permute(rest, new_ans);
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> vi;
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    vi.push_back(x);
  }
  vector<int> ans;
  permute(vi, ans);
}