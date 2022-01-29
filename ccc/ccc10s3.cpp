#include <bits/stdc++.h>
using namespace std;

const int STREET_LEN = int(1e6);
int H; // number of houses
int K;  // number of hydrants
int houses[1000];

inline int get_loc(int i) {
  return i < H ? houses[i] : houses[i-H]+STREET_LEN;
}

// this is to get the minimum hydrants you need
// to cover all houses
int get_hydrants(int hose_len){
  // here quadratic shoud be enough
  // that means, you can brute force
  int min_hydrants = H;
  int diameter = hose_len * 2;
  for(int i=0; i<H; i++){
    // use each house as start
    int cnt = 1;
    int start_loc = houses[i];
    for(int j=1; j<H; j++){ // you have H-1 houses left
      int cur = j + i;  // this is the current house index, it could be out of H
      int loc = get_loc(cur);
      if (loc - start_loc > diameter) {
        // this is out of reach
        cnt++;
        start_loc = loc;
      }
    }
    min_hydrants = min(min_hydrants, cnt);
  }
  return min_hydrants;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> H;
  for(int i=0; i<H; i++){
    cin >> houses[i];
  }
  cin >> K;
  if (K >= H) {
    cout << 0 << endl;
  }
  else {
    // you have to sort the houses first
    sort(houses, houses+H); 
    int lo = -1;
    int hi = STREET_LEN/2;
    while (lo < hi - 1) {
      int mid = (lo+hi)/2;
      // you need to function to calculate the 
      // minimum hydrants you need for all houses
      int hydrants = get_hydrants(mid);
      if (hydrants > K) {
        lo = mid;      
      } else if (hydrants <= K){
        hi = mid;
      } 
    }
    cout << hi << endl;
  }
}