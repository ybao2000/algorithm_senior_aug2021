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

int hash_4(int a, int b, int c, int d){
  return a + b * 40 + c * 40*40 + d * 40*40*40;
}
map<int, bool> memo;

int can_win(int a, int b, int c, int d){
  // you have to use recursive function + memoization
  // 2 ways: one way is to hash (combine 4 numbers together)
  int h = hash_4(a, b, c, d);
  if (memo.count(h) > 0) {
    return memo[h];
  }
  for (auto option : options){
    int a2 = a - option[0];
    int b2 = b - option[1];
    int c2 = c - option[2];
    int d2 = d - option[3];
    if ( a2 >= 0 && b2 >= 0 && c2 >=0 && d2 >= 0 
    && !can_win(a2, b2, c2, d2)){ // you made a good choice
      memo[h] = true; // don't forget to cache it
      return true;
    }
  }
  memo[h] = false;
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