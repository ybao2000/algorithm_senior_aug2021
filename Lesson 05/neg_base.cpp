#include <iostream>
#include <vector>
using namespace std;

vector<int> get_base(int n, int base){
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
  int a = 153;  // 200 - 50 + 3 => 2, 5, 3
  // cin >> a;
  vector<int> v = get_base(a, -10);
  for(int i=v.size()-1; i>=0; i--)
  {
    cout << v[i];
  }
  cout << endl;
}
