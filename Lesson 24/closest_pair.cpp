#include <bits/stdc++.h>
using namespace std;
#define px second
#define py first
const double INF = 2e9;
typedef pair<double, double> dPair;
int n;
vector<dPair> points;
set<dPair> box;


inline double sqr(double x) {return x*x; }
int compare_x(dPair a, dPair b) {return a.px < b.px;} // compare with x
int main() {
  cin >> n;
  for(int i=0; i<n; i++) {
    double x, y;
    cin >> x >> y;
    points.push_back({y, x});  // for this problem, you need to put y first!!!
  }
  sort(points.begin(), points.end(), compare_x);  // this is going to sort with x
  double best = INF;
  box.insert(points[0]);
  int left = 0; // idx of points according to x
  for(int i=1; i<n; i++){
    dPair point = points[i];
    while(left < i && point.px - points[left].px > best) {  // maintain the box
      box.erase(points[left]);
      left++;
    }
    for(auto it=box.lower_bound({point.py-best, point.px-best});
      it!= box.end() && it->py < point.py + best; 
      it++)
    {
      best = min(best, sqrt(sqr(point.py-it->py)+sqr(point.px-it->px)));
    }
    box.insert(point);
  }
  cout << best << "\n";
}