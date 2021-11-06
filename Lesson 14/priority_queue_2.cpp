#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> iPair;

int main(){
  priority_queue<iPair> q;  // by default, it's assuming the max
  // priority_queue<iPair, vector<iPair>, greater<iPair>> q; // this is to use the min
  q.push({10, 1});  // put weight first!!!
  q.push({5, 2});
  q.push({7, 3});
  q.push({20, 4});
  // for the max, it's very simple
  // what about the min?
  while(!q.empty()){
    auto node = q.top();
    cout << node.first << ", " << node.second << endl;
    q.pop();
  }

}
