#include <iostream>
#include <tuple>

using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
struct Point {
  int x, y;
};

int main(){
  // pair: built-in
  pii p1;
  p1.first = 1;
  p1.second = 2;
  pii p2 = {1, 3};
  pii p3 = {2, 3};
  cout << p3.first << ", " << p3.second << endl;

  // tuple: you need to include
  tii t1;
  cout << get<0>(t1) << ", " << get<1>(t1) << endl;
  // how to use tuple
  t1 = make_tuple(1, 2, 3);
  tii t2 = {2, 3, 4};
  cout << get<0>(t2) << ", " << get<1>(t2) << endl;

  // struct
  Point s1;
  s1.x = 1;
  s1.y = 2;
  cout << s1.x << ", " << s1.y << endl;
  Point s2 = {2, 3};

  // pair, tuple, struct are all value-type (reference type)
}