#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge {
  int weight, thick, n;
  bool operator<(const edge& e) const { // this is const function
    return weight > e.weight;
  }
};

int main(){
  priority_queue<edge> q;  // by default, it's assuming the max
  // priority_queue<iPair, vector<iPair>, greater<iPair>> q; // this is to use the min
  q.push({10, 5, 1});  // put weight first!!!
  q.push({5, 4, 2});
  q.push({7, 4, 3});
  q.push({20, 4, 4});
  // for the max, it's very simple
  // what about the min?
  while(!q.empty()){
    auto node = q.top();
    cout << node.weight << ", " << node.thick << ", " << node.n << endl;
    q.pop();
  }

}
