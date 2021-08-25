#include <iostream>
using namespace std;

// no limitation to a, k and n
int get_mod(int a, int k, int n){
  int res = 1;
  int base = a;
  int power = k;
  while(power > 0){
    if(power % 2 == 1)  {
      // odd
      res = (res * base) % n;
      power--;
    }
    else{
      // even
      base = (base * base) % n;
      power /= 2;
    }
  }
  return res;
}

int main(){
  int a = 3;
  int k = 1e9+7;
  int n = 2021;

  cout << get_mod(a, k, n) << endl;
}