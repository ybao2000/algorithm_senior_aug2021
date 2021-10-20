#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double min(double a, double b) {return a < b ? a : b;}

bool is_zero_included(int x1, int x2) {
  // return x1 * x2 <= 0; it could be overflow
  if((x1 <= 0 && x2 >= 0) || (x1 >= 0 && x2 <= 0)) return true;
  else return false;
}
double sqr(double x) {return x * x;}

double get_dist(int tx, int ty, int tz, int d){
  // spaceship is in (0, 0, 0)
  // line segment is (tx, ty, tz) and (tx-d, ty, tz)
  int x1 = tx;
  int x2 = tx-d;
  if (is_zero_included(x1, x2)) {
    return sqrt(sqr(ty) + sqr(tz));
  }
  else {
    double d1 = sqrt(sqr(x1) + sqr(ty) + sqr(tz));
    double d2 = sqrt(sqr(x2) + sqr(ty) + sqr(tz));
    return min(d1, d2);
  }
}

// beginner be careful: use reference type to change 
void rotate(int &tx, int &ty, int &tz, char dir){
  // tx, ty, tz, the location of treasure
  // d is the distance moved
  // get the minimum distant from origin (0, 0, 0) to the line segment
  int temp = tx;
  switch(dir) {
    case 'L':
      tx = ty;
      ty = -temp;
      break;
    case 'R':
      tx = -ty;
      ty = temp;
      break;
    case 'U':
      tx = tz;
      tz = -temp;
      break;
    case 'D':
      tx = -tz;
      tz = temp;
      break;
  }
}

int main(){
  int sx, sy, sz;
  int tx, ty, tz;
  cin >> sx >> sy >> sz;
  cin >> tx >> ty >> tz;
  // we want to make the spaceship in the origin (0, 0, 0)
  // we just relocate the treasure (offset)
  tx -= sx;
  ty -= sy;
  tz -= sz;
  double min_dist = 1e18; // initialize the minimum distance
  while (true) {  // infinite loop
    int d;
    char dir;
    cin >> d >> dir;
    double dist = get_dist(tx, ty, tz, d);
    min_dist = min(dist, min_dist);
    // you have to update the location of the treasure
    tx -= d;  // make treasure move backwards
    if (dir == 'E') break;
    rotate(tx, ty, tz, dir);
  }
  cout << fixed << setprecision(2) << min_dist << endl;
}