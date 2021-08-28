#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
// we are using recursive function to calculate the gcd
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
  ll a, b;
  a = 200;
  b = 60;
  ll x, y;
  ll g = get_gcd_ext(a, b, x, y);
  cout << g << ", " << x << ", " << y << endl;
}
