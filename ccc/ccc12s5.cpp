#include <bits/stdc++.h>
using namespace std;

// dp[i][j] = dp[i-1][j] + dp[i][j-1]
// dp: the total different ways to reach [i][j]
// the only difference is
// 1. this is 2D, you need 2 loops
// 2. you need to handle cats
typedef pair<int, int> iPair;
set<iPair> cats;
int dp[26][26];

int main() {
  int R, C;
  cin >> R >> C;
  int K;
  cin >> K;
  for (int i=0; i<K; i++){
    int r, c;
    cin >> r >> c;
    // you better to save it in a set
    // because it's easy to search
    cats.insert({r, c});
  }
  fill(&dp[0][0], &dp[0][0]+26*26, 0);
  for(int c=1; c<=C; c++) dp[1][c] = 1; // first row
  for(int r=1; r<=R; r++) dp[r][1] = 1; // first column
  for(iPair cat : cats) {
    int r = cat.first;
    int c = cat.second;
    dp[r][c] = 0;
    if (r == 1) {
      for(int j=c+1; j<=C; j++) dp[r][j] = 0;
    }
    if (c == 1) {
      for(int i=r+1; i<=R; i++) dp[i][c] = 0;
    }
  }
  for (int r=2; r<=R; r++){
    for(int c=2; c<=C; c++){
      if(!cats.count({r, c})){  // skip the cat
        dp[r][c] = dp[r-1][c] + dp[r][c-1];
      }
    }
  }  
  cout << dp[R][C] << "\n";
}