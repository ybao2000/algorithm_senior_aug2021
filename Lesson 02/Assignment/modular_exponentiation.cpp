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

}

int main(){
  int a = 3;
  int k = 1e9+7;
  int n = 15;
  vector<int> bin = get_bin(k);
  for(auto d: bin){
    cout << d;
  }  
  cout << endl;
  string bin2 = bitset<32>(k).to_string();
  cout << bin2 << endl;

  // cout << get_mod(a, k, n) << endl;
}