#include <bits/stdc++.h>  // this is allowed for g++ compiler
using namespace std;
typedef long long ll;

const int SIZE = 200001;  // for the offset of 1
int N;
ll P[SIZE], W[SIZE], D[SIZE];

ll total_time(ll x) {
  ll t = 0;
  for (int i=0; i<N; i++){
    if (x > P[i] + D[i]) {  // this means they have to move right
      t += (x - P[i]-D[i]) * W[i];
    } else if (P[i] > x + D[i]) { // they have to move left
      t += (P[i] - D[i] - x) * W[i];
    }
  }
  return t;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i=0; i<N; i++){
    cin  >> P[i] >> W[i] >> D[i];    
  }
  int left = 0, right = 1e9;
  while (left < right){
    int mid = (left + right)/2;
    ll t_mid = total_time(mid);
    ll t_mid_1 = total_time(mid+1);
    if (t_mid > t_mid_1) {
      left = mid + 1;
    }
    else {
      right = mid;
    }
  }
  cout << total_time(left) << "\n"; // "\n" a little bit faster than endl
}
