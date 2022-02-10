#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, T;
struct seg {
  int y, x1, x2, t;  
};
vector<seg> segs;
set<int> sx;
vector<int> xs;
unordered_map<int, int> mp;
int ts[2002];
int compare_y(const seg &a, const seg &b) {return a.y < b.y;}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  cin >> T;
  for(int i=0; i<N; i++){
    int x1, y1, x2, y2, t;
    cin >> x1 >> y1 >> x2 >> y2 >> t;
    segs.push_back({y1, x1, x2, t});  // entering
    segs.push_back({y2, x1, x2, -t}); //  leaving
    sx.insert(x1);
    sx.insert(x2);
  }
  // set is auto-matically ordered
  // convert the set into the ordered vector
  xs.assign(sx.begin(), sx.end());
  for(size_t i=0; i<xs.size(); i++){
    mp[xs[i]] = i;
  }
  // before do the sweep line, you also need to srot segs
  sort(segs.begin(), segs.end(), compare_y);
  ll area = 0;
  for (size_t i=0; i<segs.size()-1; i++){
    for(int j=mp[segs[i].x1]; j<mp[segs[i].x2]; j++){
      ts[j] += segs[i].t; // change ts[j]
    }
    for(size_t j=0; j<sx.size()-1; j++){
      if(ts[j] >= T) {  // thick enough
        area += ((ll)xs[j+1]-xs[j]) *(segs[i+1].y - segs[i].y);
      }
    }
  }
  cout << area << "\n";
}