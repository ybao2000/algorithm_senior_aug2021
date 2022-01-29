#include <bits/stdc++.h>
using namespace std;

int const INF = 2e9;
int const SIZE = 100;
int const MAX_SIZE = 6000;
int N;
int clubs[SIZE];
int amount;
int dp[MAX_SIZE];

void solve() {
  fill(dp, dp+MAX_SIZE, INF);
  dp[0] = 0;
  for(int i=1; i<=amount; i++){
    for(int j=0; j<N; j++){
      int remain = i - clubs[j];
      if(remain >= 0 && dp[remain] != INF){
        dp[i] = min(dp[i], dp[remain]+1);
      }
    }
  }
}

int main() {
  cin >> amount;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> clubs[i];
  }
  solve();
  if(dp[amount] == INF) {
    printf("Roberta acknowledges defeat.\n");
  }
  else {
    printf("Roberta wins in %d strokes.", dp[amount]);
  }
}
