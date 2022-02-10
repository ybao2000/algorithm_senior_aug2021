#include <bits/stdc++.h>
using namespace std;

int n;
int options[5][4] = {
  {2, 1, 0, 2},
  {1, 1, 1, 1},
  {0, 0, 2, 1},
  {0, 3, 0, 0},
  {1, 0, 0, 1}
};

// don't use map with complicated tuple/struct 
// pair is good because map/set already supported pair
bool dp[31][31][31][31];  // this is your result
bool solved[31][31][31][31];  // this is to show if solved or not

bool can_win(int a, int b, int c, int d){
  // you have to use recursive function + memoization
  // another way is using multi-dimensional arrays
  if (solved[a][b][c][d]) {
    return dp[a][b][c][d];
  }
  for (auto option : options){
    int a2 = a - option[0];
    int b2 = b - option[1];
    int c2 = c - option[2];
    int d2 = d - option[3];
    if ( a2 >= 0 && b2 >= 0 && c2 >=0 && d2 >= 0 
    && !can_win(a2, b2, c2, d2)){ // you made a good choice
      solved[a][b][c][d] = true;
      dp[a][b][c][d] = true; // don't forget to cache it
      return true;
    }
  }
  solved[a][b][c][d] = true;
  return false;
}

int main() {
  cin >> n;
  for (int i=0; i<n; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (can_win(a, b, c, d)){
      cout << "Patrick\n";
    }
    else{
      cout << "Roland\n";
    }
  }
}