#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
  int n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;
  ll ca = n / a;
  ll cb = n / b;
  ll gcd = __gcd(a, b);
  ll lcm = a / gcd * b;
  ll c3 = n / lcm;
  ll total = ca * p + cb * q - c3 * (p > q ?  q : p);
  cout << total << endl;
}