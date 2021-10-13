#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
struct Point {
  double x, y;  
  bool operator< (const Point &p2){
    if (y < p2.y) return true;
    else if (y > p2.y) return false;
    else return x < p2.x; // this doen't matter
  }
};

double sqr(double x) {return x*x;}
double dist2(Point &p1, Point &p2){
  return sqr(p1.x-p2.x) + sqr(p1.y-p2.y);
}
double max(double x, double y) {return x < y ? y : x;}
double min(double x, double y) {return x < y ? x : y;}

int main(){
  int n;
  cin >> n;
  vector<Point> sheeps;
  for(int i=0; i<n; i++){
    double x, y;
    cin >> x;
    cin >> y;
    sheeps.push_back({x, y});
  }
  // step 1: you need to sort it
  sort(sheeps.begin(), sheeps.end());

  // init the solution
  vector<Point> results;
  // step 2: iterate
  double longest = 1e18;
  for (auto &sheep : sheeps){
    double d = sqr(sheep.y);
    if( d> longest) break;
    double xl = 0;
    double xr = 1000;
    bool is_valid = true;
    for (auto & sheep2 : results){
      if (sheep2.x < sheep.x) {
        // on the left
        double x = (sqr(sheep.x)+sqr(sheep.y)-sqr(sheep2.x)-sqr(sheep2.y))/(sheep.x-sheep2.x)/2.0;
        xl = max(x, xl);
      }
      else if (sheep2.x > sheep.x){
        double x = (sqr(sheep.x)+sqr(sheep.y)-sqr(sheep2.x)-sqr(sheep2.y))/(sheep.x-sheep2.x)/2.0;
        xr = min(x, xr);
      }
      else{
        is_valid = false;
        break;
      }   
    }
    if(is_valid){
      if(xl < xr || abs(xl-xr) < 1.e-8) {
        results.push_back(sheep);   // you found it
      }
    }     
  }
  cout << fixed << setprecision(2);
  for (auto & sheep : results){
    cout << "The sheep at (" << sheep.x << ", " << sheep.y << ") might be eaten." << endl;
  }
}