#include <iostream>
using namespace std;
typedef long long ll;

ll get_gcd_ext(ll a, ll b, ll& x, ll& y){
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll g = get_gcd_ext(b, a%b, x1, y1);
  x = y1;
  y = x1 - y1 * (a/b);
  return g;
}

int main(){
  ll A, B, C;
  cin >> A >> B >> C;
  ll max_num = 5e18;
  ll gcd, x, y;
  gcd = get_gcd_ext(A, B, x, y);
  if (C % gcd == 0){
    ll m = -C/gcd;
    ll mx = m * x;
    ll my = m * y;
    if (abs(mx) > max_num || abs(my) > max_num){
      cout << -1 << endl;
    }
    else {
      cout << mx << " " << my << endl;
    }
  }
  else{
    cout << -1 << endl;  
  }
}