#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int> tii;
struct Point {
  int x, y;
  // definition for < operator
  bool operator< (const Point &p2){
    if (x < p2.x) return true;
    else if (x > p2.x) return false;
    else if(y < p2.y) return true;
    else return false;
  }
};

int main() {
  // pii P[5];
  // P[0] = {1, 1};
  // P[1] = {2, 5};
  // P[2] = {3, 3};
  // P[3] = {2, 4};
  // P[4] = {2, 3};
  // // how to sort the array?
  // // sort first with first, then sort with second (default behavior for pair)
  // sort(P, P+5);
  // for(auto elem : P){
  //   cout << elem.first << ", " << elem.second << endl;
  // }
  // tii T[5];
  // for(int i=0; i<5; i++){
  //   T[i] = make_tuple(5-i%2, 6-i%3);
  // }
  // // for (auto elem: T){
  // //   cout << get<0>(elem) << ", " << get<1>(elem) << endl;
  // // }
  // sort(T, T+5);
  // for (auto elem: T){
  //   cout << get<0>(elem) << ", " << get<1>(elem) << endl;
  // }
  Point S[5];
  for(int i=0; i<5; i++){
    S[i].x = 5-i%2;
    S[i].y = 6-i%3;
  }
  sort(S, S+5);
  for(auto elem : S){
    cout << elem.x << ", " << elem.y << endl;
  }
  Point s1 = {7, 8};
  Point s2 = {8, 7};
  cout << (s1 < s2) << endl;
}