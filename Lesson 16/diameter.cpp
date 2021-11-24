#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 20;
int N;
vector<int> adj[SIZE];
queue<int> q;
bool visited[SIZE];
int dists[SIZE];
int max_node;
int max_dist;

void bfs(int start){
  fill(visited, visited+SIZE, false);
  fill(dists, dists+SIZE, -1);
  q.push(start); // every time you push, make it visited, and update the dists
  visited[start] = true;
  dists[start] = 0;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    for(int sub : adj[cur]){
      if(!visited[sub]){
        int new_dist = dists[cur] + 1;
        if (new_dist > max_dist){
          max_dist = new_dist;
          max_node = sub;
        }
        q.push(sub);
        visited[sub] = true;
        dists[sub] = new_dist;
      }
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
  // try BFS first
  max_dist = 0;
  bfs(1);
  // cout << "max node" << max_node << ", max dist" << max_dist << endl;
  max_dist = 0;
  int node_1 = max_node;
  bfs(max_node);
  cout << "diameter is " << max_dist << ", from " << node_1 << " to " << max_node << endl;
}