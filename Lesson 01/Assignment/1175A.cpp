#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int t;
  cin >> t;
  for(int i=0; i<t; i++){ // we are solving t queries
    ll n, k;
    cin >> n >> k;
    ll moves = 0;  // intialize the result
    while(n > 0){
      ll rem = n % k;
      if (rem == 0){
        n /= k;
        moves++;
      }
      else {
        n -= rem;
        moves += rem;
      }
    }
    cout << moves << endl;
  }
}