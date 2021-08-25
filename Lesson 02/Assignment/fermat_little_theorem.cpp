#include <iostream>
using namespace std;

// n is prime (relative small)
// a is not divisible by n
// usually n is small
int get_mod(int a, int k, int n){
  int rem = k % (n-1);
  int result = 1;
  for(int i=0; i<rem; i++){
    result = (result * a) % n;  // don't forget to mod
  }
  return result;
}

int main(){
  int a = 3;
  int k = 100;
  int n = 13;

  cout << get_mod(a, k, n) << endl;
}