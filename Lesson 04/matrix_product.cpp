#include <iostream>
using namespace std;
typedef long long ll;
typedef ll(*mat)[2];

// how to define a matrix?
// I need a function which take 2 matrix, and return the product(multiplication)
// how to return the matrix?
// if it's a 1D array
// ll* foo_1d(){
//   ll D[2];
//   return D;
// }

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

int main() {
  ll A[2][2] = {
    {1, 2},
    {3, 4}
  };
  ll B[2][2]  {
    {5, 6},
    {7, 8}
  };
  mat C = matrix_product(A, B);
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      cout << C[i][j] << " ";
    }
    cout << endl;   // new line
  }
}