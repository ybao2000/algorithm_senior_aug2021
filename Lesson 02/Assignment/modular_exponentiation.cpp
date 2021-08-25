#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;

vector<int> get_bin(ll k){
  vector<int> bin;
  while(k>0){
    bin.push_back(k%2);
    k = k/2;
  }
  return bin;
}

// no limitation to a, k and n
int get_mod(int a, int k, int n){
  vector<int> bin = get_bin(k);
  vector<int> apow;
  int exp = a % n;
  for(int i=0; i<bin.size(); i++){
    apow.push_back(exp);
    exp = (exp*exp) %n;    
  }
  int result = 1;
  for(int i=0; i<bin.size(); i++){
    if(bin[i] > 0){
      result = (result * apow[i]) % n;
    }
  }
  return result;
}

int main(){
  int a = 3;
  int k = 1e9+7;
  int n = 2021;
  cout << get_mod(a, k, n) << endl;

  // vector<int> bin = get_bin(60);
  // for(auto d: bin){
  //   cout << d;
  // }  
  // cout << endl;
  // string bin2 = bitset<32>(60).to_string();
  // cout << bin2 << endl;

  // cout << get_mod(a, k, n) << endl;
}