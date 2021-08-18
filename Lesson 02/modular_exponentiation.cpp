#include <string>
#include <bits/stdc++.h>
using namespace std;
// for any a, big k and any n

int get_remainder(int a, int k, int n){

}

int main(){
  int a = 3;
  int k = 20000000;
  int n = 2022;

  // I want binary of k
  string bin = bitset<32>(k).to_string();
  cout << bin << endl;
  map<int, int> map1;
  map1[0] = 1;
  map1[1] = a % n;
  for(int i=1; i<32; i++){
    int rem = (map1[i-1] * map1[i-1] ) % n;
    map1[i] = rem;
  }
  int res = 1;
  for(int i= bin.size()-1; i>=0; i--){
    if(bin[i] == '1'){
      res = (res * map1[i]) % n;
    }
  }
  cout << res << endl;
}