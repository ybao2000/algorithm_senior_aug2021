#include <bits/stdc++.h>
using namespace std;

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
  int n = 2021;
  for(int i=2; i<=n; i++){
    if(isPrime(i)){
      cout << i;
    }
    cout << " ";
  }
  cout << endl;
}
