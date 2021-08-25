#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
// we are using recursive function to calculate the gcd
ull get_gcd(ull a, ull b){
  if (b == 0) return a;
  return get_gcd(b, a%b);
}

int get_gcd_iter(ull a, ull b){
  if(b == 0) return a;
  ull r = a % b;
  while(r > 0){
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int main(){
  ull a, b;
  a = 122029023030205;
  b = 2020202020200;
  cout << get_gcd_iter(a, b) << endl;
}
