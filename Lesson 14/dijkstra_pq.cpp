#include <iostream>
#include <vector>
// #include <climits>
#include <queue>
using namespace std;

typedef pair<int, int> iPair;
const int SIZE = 100;
const int MAX = int(1e9);

int N, M;
vector<iPair> adj[SIZE];
bool visited[SIZE];
priority_queue<iPair, vector<iPair>, greater<iPair>> pq;  // need min
int weights[SIZE];

void dijkstra(int start){
  fill(visited, visited+SIZE, false);
  fill(weights, weights+SIZE, MAX);
  pq.push({0, start});
  visited[start] = true;
  weights[start] = 0;
  while(!pq.empty()){
    iPair cur = pq.top();
    pq.pop();
    int w = cur.first;
    int n = cur.second;
    visited[n] = true;
    for(iPair edge: adj[n]){
      int n2 = edge.second;
      if (!visited[n2]) {  // only for unvisited
        int w2 = w + edge.first;
        if (w2 < weights[n2]){
          weights[n2] = w2;
          pq.push({w2, n2});
        }
      }
    }
  }
  for (int i=1; i<=N; i++){
    cout << weights[i] << endl;
  }
}

int main(){
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({w, b});  // w first, node second
    adj[b].push_back({w, a}); // undirected
  }
  int start = 1;
  dijkstra(start);  
}
