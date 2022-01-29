#include <bits/stdc++.h>
using namespace std;

int const INF = 2e9;
int const SIZE = 100;
int const MAX_SIZE = 30000;
int N;
int coins[SIZE];
int amount;
int visited[MAX_SIZE];  // this is to show if it's already calculated
int memo[MAX_SIZE]; // this is going to store the result

// return the minimum coins for the amount
int dp(int x) {
  if (x < 0) return INF;  // not possible
  else if(x == 0) return 0;
  else if (visited[x]) return memo[x];
  else {
    int val = INF;
    for(int i=0; i<N; i++){
      int coin = coins[i];
      int res = dp(x-coin);
      if(res != INF) {
        val = min(val, res + 1);
      }
    }
    visited[x] = true;
    memo[x] = val;
    return val;
  }
}

int main() {
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> coins[i];
  }
  cin >> amount;
  fill(visited, visited+MAX_SIZE, false);
  int ans = dp(amount);
  if (ans == INF) cout << -1 << "\n";
  else cout << ans << "\n";
}