#include <bits/stdc++.h>
using namespace std;

int const INF = 2e9;
int const SIZE = 100;
int N;
int coins[SIZE];
int amount;

// return the minimum coins for the amount
int dp(int x) {
  if (x < 0) return INF;  // not possible
  else if(x == 0) return 0;
  else {
    int val = INF;
    for(int i=0; i<N; i++){
      int coin = coins[i];
      int res = dp(x-coin);
      if(res != INF) {
        val = min(val, res + 1);
      }
    }
    return val;
  }
}

int main() {
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> coins[i];
  }
  cin >> amount;
  int ans = dp(amount);
  if (ans == INF) cout << -1 << "\n";
  else cout << ans << "\n";
}