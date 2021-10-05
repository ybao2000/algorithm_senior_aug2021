#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

double max(double a, double b) {return a>b? a : b;}

int main() {
  int N;
  cin >> N;
  pair<int, int> p[N];
  for(int i=0; i<N; i++){
    cin >> p[i].first >> p[i].second;
  }
  // we need to sort
  // fortunately, by default, you sort the pair according to followign rule
  // sort first first, second second
  sort(p, p+N);
  double max_speed = 0;
  for(int i=0; i<N-1; i++){
    double dt = p[i+1].first - p[i].first;
    double dx = p[i+1].second - p[i].second;
    max_speed = max(max_speed, abs(dx/dt));
  }
  cout << fixed << setprecision(6) << max_speed << endl;
}