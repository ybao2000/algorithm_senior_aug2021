#include <iostream>
using namespace std;
typedef long long ll;
typedef ll(*mat)[2];

mat matrix_product(mat A, mat B, ll t){
  mat C = new ll[2][2];
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      C[i][j] = 0;  // don't forget to initialize it
      for(int k=0; k<2; k++){
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % t;
      }
    }
  }
  return C;
}

mat get_mod(mat A, ll k, ll t){
  ll power = k;
  mat base = A;
  ll I[2][2] = {
    {1, 0},
    {0, 1}
  };
  mat res = I;
  while (power > 0) {
    if(power % 2 == 1){
      res = matrix_product(res, base, t);
      power--;
    }
    else {
      base = matrix_product(base, base, t);
      power /= 2;
    }
  }
  return res;
}

int main(){
  ll A[2][2] = {
    {1, 1},
    {1, 0}
  };  
  ll n;
  cin >> n;
  ll k = n-1;
  ll t = 1e9;
  
  mat res = get_mod(A, k, t);
  cout << res[0][0] << endl;
}
