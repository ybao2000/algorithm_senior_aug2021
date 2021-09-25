#include <iostream>
using namespace std;

struct Point {
  int x, y;
};

inline int max(int a, int b) {return a < b ? b : a;}
inline int min(int a, int b) {return a < b ? a : b;}

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
  return det > 0 ? 2 : 1; 
}

bool on_segment(Point a, Point b, Point c){
  if(c.x <= max(a.x, b.x) && c.x >= min(a.x, b.x)
    && c.y <= max(a.y, b.y) && c.y >=min(a.y, b.y)){
      return true;
    }
    return false;
}

bool intersect(Point p1, Point q1, Point p2, Point q2){
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);
  if(o1 != o2 && o3 != o4) return true;
  if (o1 == 0 && on_segment(p1, q1, p2)) return true;
  if (o2 == 0 && on_segment(p1, q1, q2)) return true;
  if (o3 == 0 && on_segment(p2, q2, p1)) return true;
  if (o4 == 0 && on_segment(p2, q2, q1)) return true;
  return false;
}

int main(){
  Point p1 = {1, 1};
  Point p2 = {10, 10};
  Point p3 = {1, 10};
  Point p4 = {10, 1};
  cout << intersect(p1, p3, p2, p4) << endl;
}