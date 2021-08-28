#include <iostream>
using namespace std;
typedef long long ll;
typedef ll(*mat)[2];

mat matrix_product(mat A, mat B){
  mat C = new ll[2][2];
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      C[i][j] = 0;  // don't forget to initialize it
      for(int k=0; k<2; k++){
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}

int main(){
  ll C[2][2] = {
    {1, 1},
    {1, 0}
  };
  int n;
  cin >> n; // n is the seq no of the fibo sequence
  mat A = C;
  for(int i=2; i<n; i++){
    A = matrix_product(A, C);
  }
  cout << A[0][0] << endl;

}
