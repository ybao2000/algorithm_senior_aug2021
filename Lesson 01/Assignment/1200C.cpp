#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
  ll n, m;
  int q;
  cin >> n >> m >> q;
  ll gcd = __gcd(n, m);
  ll p1 = n/gcd;  // p1 is the partition number of sector 1
  ll p2 = m/gcd;  // p2 is the partition number of section 2
  int sx, ex;
  ll sy, ey;
  for(int i=0; i<q; i++){
    cin >> sx >> sy >> ex >> ey;
    // convert (sx, sy) into session #
    ll s1 = (sx == 1) ? (sy-1)/p1 : (sy-1)/p2;
    ll s2 = (ex == 1) ? (ey-1)/p1 : (ey-1)/p2;
    if (s1 == s2){  // same session
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
}