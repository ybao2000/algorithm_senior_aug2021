// f(n) = f(n-1) +2 f(n-2) + 5 f(n-4) + f(n-5)
// f(n) = f(n-1) + f(n-2) // fibo 
#include <iostream>
using namespace std;
typedef long long ll;
const int SIZE = 5;
const ll MOD = 1e9+7;
typedef ll(*mat)[SIZE];

mat matrix_product(mat A, mat B){
  mat C = new ll[SIZE][SIZE];
  for(int i=0; i<SIZE; i++){
    for(int j=0; j<SIZE; j++){
      C[i][j] = 0;  // don't forget to initialize it
      for(int k=0; k<SIZE; k++){
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
      }
    }
  }
  return C;
}

mat power_mod(mat A, ll k){
  ll power = k;
  mat base = A;
  ll I[SIZE][SIZE] = {
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1}
  };
  mat res = I;
  while (power > 0) {
    if(power % 2 == 1){
      res = matrix_product(res, base);
      power--;
    }
    else {
      base = matrix_product(base, base);
      power /= 2;
    }
  }
  return res;
}

int main(){
  ll A[SIZE][SIZE] = {
    {1, 2, 0, 5, 1},
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0}
  };  
  int t;
  cin >> t;
  for(int i=0; i<t; i++){
    ll T[5];
    ll n;
    for(int j=0; j<5; j++){
      cin >> T[j];
    }
    cin >> n;
    if (n<5){
      cout << T[n] << endl;
    }
    else {  // n starting from 5
      mat res = power_mod(A, n-4);
      ll total = 0;
      for(int j=0; j<5; j++){
        total = (total + res[0][j] * T[4-j] % MOD) % MOD;
      }
      cout << total << endl;
    }
  }
}
