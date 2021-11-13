#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int SIZE = 11; // we don't want offset

int N, M;
vector<int> adj[SIZE];   // this is the adjacency list

queue<int> q;
bool visited[SIZE];  // array is much faster than other data structure

void bfs(int start){
  fill(visited, visited+SIZE, false);
  q.push(start);
  // set visit right after push
  visited[start] = true;
  while(!q.empty()){
    int n = q.front();
    q.pop();
    cout << n << endl;
    for(int n2: adj[n]){ // go through all the neighbors
      if (!visited[n2]){
        q.push(n2);
        visited[n2] = true;
      }
    }
  }
}

int main(){
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  bfs(1);
}