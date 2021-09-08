#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> get_base(ll n, int base){
  vector<int> v;
  if(n==0) {
    v.push_back(0);
  }
  while(n != 0){
    int rem = n % base;
    n /= base;
    if(rem < 0) {
      rem -= base;  // base is negativen
      n++;
    }
    v.push_back(rem);
  }
  return v;
}

int main(){
  ll p;
  int k;
  cin >> p >> k;
  vector<int> v = get_base(p, -k);
  int len = v.size();
  cout << len << endl;
  for(int i=0; i<len; i++){
    if(i>0){
      cout << " ";  // the first element no space, all other elements has space
    }
    cout << v[i];
  }
  cout << endl;
}
