#include <iostream>
using namespace std;
typedef long long ll;

ll fibo_iter(ll n, ll t){
  if (n <= 2) return 1;
  ll a = 1;
  ll b = 1;
  ll c;
  for(int i=2; i<n; i++){
    c = (a + b) % t;
    a = b;
    b = c;
  }
  return c;
}
int main(){
  ll t = 1e9;
  ll n;
  cin >> n;
  cout << fibo_iter(n, t) << endl;
}