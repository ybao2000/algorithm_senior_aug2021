#include <iostream>
using namespace std;

// no limitation to a, k and n
int get_mod(int a, int k, int n){
  int power = k;
  int base = a;
  int res = 1;
  while (power > 0){
    if (power % 2 == 1){  // odd
      res = (res * base) % n;
      power--;
    }
    else{ // even
      base = (base * base) % n;
      power /= 2;
    }
  }
  return res;
}

int main(){
  int a = 3;
  int k = 15;
  int n = 15;

  cout << get_mod(a, k, n) << endl;
}