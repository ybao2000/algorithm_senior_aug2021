#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
  int n;
  ll x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  vector<pair<ll, ll>> dists;
  ll x, y;
  // stores all distances
  for(int i=0; i<n; i++){
    cin >> x >> y;
    ll d1 = (x-x1)*(x-x1)+(y-y1)*(y-y1);
    ll d2 = (x-x2)*(x-x2)+(y-y2)*(y-y2);
    dists.push_back(pair<ll, ll>(d1, d2));
  }
  dists.push_back(pair<ll, ll>(0, 0));
  // n is small, so we can use brute force to get the answer
  ll result = 1e18; // we initialize the result to be a super big number
  for(auto p1: dists){  // loop through all the points
    // this is for first foutain
    ll r1 = p1.first;
    // for each r1, you need to find r2 (this min r2 which can cover all other flowers that r1 cannot water)
    ll r2 = 0;
    for (auto p2: dists) { // loop through all the points again
      if (p2.first > r1){ // this flower cannot be watered by r1
        r2 = max(r2, p2.second);    // you have to include this in the r2
      }
    }
    result = min(result, r1+r2);  // r1+r2 has to be as small as possible
  }
  cout << result << endl;
}