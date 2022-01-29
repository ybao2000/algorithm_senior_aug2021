#include <bits/stdc++.h>
using namespace std;

int const INF = 2e9;
int const SIZE = 100;
int const MAX_SIZE = 3000000;
int N;
int coins[SIZE];
int amount;

int state[MAX_SIZE];

int dp(int x){
  fill(state, state+MAX_SIZE, INF);
  state[0] = 0; // 0 coins to make 0
  for(int i=1; i<=x; i++){
    int ans = INF;
    for(int k=0; k<N; k++) {
      int remain = i - coins[k];
      if(remain >= 0) {
        if(state[remain] != INF) {
          ans = min(ans, state[remain] + 1);
        }
      }
    }
    state[i] = ans;
  }
  return state[x];
}

int main() {
  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> coins[i];
  }
  cin >> amount;
  int ans = dp(amount);
  if (ans == INF) cout << -1 << "\n";
  else cout << ans << "\n";  
}