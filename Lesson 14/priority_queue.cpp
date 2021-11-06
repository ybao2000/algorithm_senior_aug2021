#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  // priority_queue<int> q;  // by default, it's assuming the max
  priority_queue<int, vector<int>, greater<int>> q; // this is to use the min
  q.push(10);
  q.push(5);
  q.push(7);
  q.push(20);
  // for the max, it's very simple
  // what about the min?
  while(!q.empty()){
    cout << q.top() << endl;
    q.pop();
  }

}
