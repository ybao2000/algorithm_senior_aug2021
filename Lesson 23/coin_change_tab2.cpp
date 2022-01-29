#include <bits/stdc++.h>
using namespace std;

int const INF = 2e9;
int const SIZE = 100;
int const MAX_SIZE = 3000000;
int N;
int coins[SIZE];
int amount;

int dp[MAX_SIZE];

int solve(int x){
  fill(dp, dp+MAX_SIZE, INF); // initialize the dp
  dp[0] = 0; // base case, boundary condition
  for(int i=1; i<=x; i++){  // iteration
    int ans = INF;
    for(int k=0; k<N; k++) {
      int remain = i - coins[k];
      if(remain >= 0) {
        if(dp[remain] != INF) {
          ans = min(ans, dp[remain] + 1);
        }
      }
    }
    dp[i] = ans;
  }
  return dp[x];
}

int main() {
  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> coins[i];
  }
  cin >> amount;
  int ans = solve(amount);
  if (ans == INF) cout << -1 << "\n";
  else cout << ans << "\n";  
}