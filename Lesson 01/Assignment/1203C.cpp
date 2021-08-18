#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll get_gcd(ll a, ll b){
  if(b == 0) {
    return a;
  }
  return get_gcd(b, a%b);
}

ll count_factors(ll g){
  ll icount = 0; // initialize the counter
  for (ll i=1; i*i<=g; i++){
    if (g % i == 0) { // i is a factor
      if (i*i == g){
        icount++;
      }
      else{
        icount += 2;
      }
    }
  }
  return icount;
}

int main() {
  int n;
  cin >> n;
  ll gcd = 0;
  ll a;
  // first step, calculate the gcd for all numbers
  for(int i=0; i<n; i++){
    cin >> a;
    gcd = get_gcd(gcd, a);
  }
  // second step, find all factors for the gcd
  ll numbers = count_factors(gcd);
  cout << numbers << endl;
}