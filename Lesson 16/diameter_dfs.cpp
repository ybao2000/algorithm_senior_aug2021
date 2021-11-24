#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 20;
int N;
vector<int> adj[SIZE];
int max_node;
int max_dist;

void dfs(int node, int from, int dist){
  if (dist > max_dist) {
    max_dist = dist;
    max_node = node;
  }
  for (int sub: adj[node]){
    if (sub != from){
      dfs(sub, node, dist+1);
    }
  }
}

int main(){
  cin >> N;
  for(int i=0; i<N-1; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  max_dist =0;
  dfs(1, -1, 0);   // start, from, dist
  //cout << "max node" << max_node << ", max dist" << max_dist << endl;
  max_dist = 0;
  int node_1 = max_node;
  dfs(max_node, -1, 0);
  cout << "diameter is " << max_dist << ", from " << node_1 << " to " << max_node << endl;
}