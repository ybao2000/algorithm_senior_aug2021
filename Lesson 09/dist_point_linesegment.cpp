#include <iostream>
#include <cmath>  // we need sqrt
using namespace std;

struct Point {
  double x, y;
};

double min(double x, double y ) {return x < y ? x : y;}
double sqr(double x) {return x*x;}  // square function
double dist(Point a, Point b) {
  return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y));
}

double calc_k(Point a, Point b, Point c){
  double d2 = sqr(b.x-a.x) + sqr(b.y-a.y); // d2 always positive
  double t = (b.x-a.x)*(c.x-a.x) + (b.y-a.y)*(c.y-a.y);
  return t/d2;
}


double dist_segment_point(Point a, Point b, Point c){
  double k = calc_k(a, b, c);
  Point d = {a.x + k * (b.x-a.x), a.y + k * (b.y-a.y)};
  if(k>=0 && k<=1) return dist(c, d);
  else return min(dist(a, c), dist(b, c));
}

int main() {
  Point p1 = {0, 0};
  Point p2 = {1, 1};
  Point p3 = {1, 0};
  // cout << calc_k(p1, p2, p3) << endl;
  cout << dist_segment_point(p1, p2, p3) << endl;
}