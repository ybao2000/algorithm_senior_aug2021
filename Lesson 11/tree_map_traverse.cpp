#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
unordered_map<string, vector<string>> tree;

void pre_order(string s){
  cout << s << endl;
  if(tree.find(s) != tree.end()){ // make sure s is in the map
    for(auto child: tree[s]){ // for all children, call pre_order
      pre_order(child);
    }
  }
}

void post_order(string s){
  if(tree.find(s) != tree.end()){ // make sure s is in the map
    for(auto child: tree[s]){ // for all children, call pre_order
      post_order(child);
    }
  }
  cout << s << endl;
}

void bfs(string s){
  queue<string> q;
  q.push(s);

  while(!q.empty()){
    string cur_s = q.front();
    q.pop();
    cout << cur_s << endl;
    if(tree.find(cur_s) != tree.end()){
      for(auto child: tree[cur_s]){
        q.push(child);
      }
    }
  }
}

int main(){
  int N;
  cin >> N;
  string s1, s2;

  for(int i=0; i<N; i++){
    cin >> s1 >> s2;
    tree[s2].push_back(s1);
  }

  // pre_order("a");
  // post_order("a");
  bfs("a");
}