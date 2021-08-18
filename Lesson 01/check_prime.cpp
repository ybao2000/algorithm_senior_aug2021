#include <bits/stdc++.h>
using namespace std;

// a function to return 
// if n is prime, then return true; otherwisse, return false
bool isPrime(int n){
  // int sn = sqrt(n);
  for(int i=2; i*i <= n; i++){
    if(n % i == 0) {
      return false;
    }
  }
  return true;
}

int main(){
  // int n = 1e9+7;
  int n = 2019;
  if(isPrime(n)){
    cout << "Prime" << endl;
  } 
  else {
    cout << "Composite" << endl;
  }
}
