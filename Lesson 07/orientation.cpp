#include <iostream>
using namespace std;

// int orientation(double x1, double y1, double x2, double y2, double x3, double y3){

// }
// one is to learn struct
// struct is very similar to class
// the 2 differences between struct and class
// 1. struct is value type (simple type), class is reference type (complex type)
// 2. struct member is public by default, class member is private by default
struct Point {
  int x, y;
};

// 0 -> collinear
// 1 -> clockwise
// 2 -> counter-clockwise
int orientation(Point a, Point b, Point c){
  int d1 = b.x - a.x;
  int d2 = b.y - a.y;
  int d3 = c.x - a.x;
  int d4 = c.y - a.y;
  int det = d1 * d4 - d2 * d3;
  if (det == 0) return 0;
  return det > 0 ? 1 : 2; 
}

int main(){
  Point p;
  p.x = 10;
}