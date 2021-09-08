// f(n) = 16 f(n-1) + 9 f(n-2) + 4 f(n-3) + 1 f(n-4) + 0 f(n-5)
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
    {16, 9, 4, 1, 0},
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0}
  };  


  ll n;
  cin >> n;
  // split n into decade and year in the decade
  ll d = n/10;  // this is for new trees
  ll y = n%10;  // 0, 1, 2, 3, 4 - the older trees still alive, 5, 6, 7, 9 - the older trees dead
  ll v[5];  // initial new trees
  v[0] = 1;
  v[1] = 16 * v[0];
  v[2] = 16 * v[1] + 9 * v[0];
  v[3] = 16 * v[2] + 9 * v[1] + 4 * v[0];
  v[4] = 16 * v[3] + 9 * v[2] + 4 * v[1] + v[0];
  if(d == 0){
    cout << v[0] << endl;
  }
  else if(d==1){
    cout << v[0] + v[1] << endl;
  }
  else if (d == 2) {
    cout << v[0] + v[1] + v[2] << endl;
  }
  else if (d == 3){
    cout << v[0] + v[1] + v[2] + v[3] << endl;
  }
  else {
      // d >= 4
    mat res = power_mod(A, d-3);
    ll w[5];
    for (int i=0; i<5; i++){
      w[i] = 0;
      for(int j=0; j<5; j++){
        w[i] = (w[i] + res[i][j] * v[3-j] % MOD) % MOD;
      }
    }
    ll t = w[0] + w[1] + w[2] + w[3];
    if (y < 5){
      t += w[4];
    }
    cout << t % MOD << endl;
  }
  

}
