#include <bits/stdc++.h>
using namespace std;
#define px first
#define py second
typedef pair<double, double> dPair;
int n;
vector<dPair> points;
vector<dPair> H;  // to store the convex hull

// positive if A, B, C is anti-clockwise, 
// negative is A, B, C is clockwise
// 0 if A, B, C is coolinear
double cross_prod(dPair A, dPair B, dPair C) {
  return (B.px - A.px) * (C.py-A.py) - (C.px-A.px) * (B.py - A.py);
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++){
    double x, y;
    cin >> x >> y;
    points.push_back({x, y}); // for convex hull, you put x first
  }
  sort(points.begin(), points.end()); // sorted according to x
  int k = 0;  // k is the number of vertice of convex hull
  H = vector<dPair> (n*2);  // at most 2n, we just make a big vector
  // build lower hull
  for(int i=0; i<n; i++){
    while(k>=2 && cross_prod(H[k-2], H[k-1], points[i]) <= 0) k--;
    H[k++] = points[i];  // H[k] = points[k], k++;
  }
  // build upper hull
  // i start from n-2 because n-1 is the point which both hulls will have in common
  // t = k+1 so that the uppper hull has at least two points to begin with
  int t = k+1;
  for(int i=n-2; i>=0; i--){
    while (k>=t && cross_prod(H[k-2], H[k-1], points[i]) <= 0) k--;
    H[k++] = points[i];
  }
  // don't forget to the remove the last points
  H.resize(k-1);  // remove the last point
  for(auto pt: H){
    cout << pt.px << ", " << pt.py << "\n";
  }
}