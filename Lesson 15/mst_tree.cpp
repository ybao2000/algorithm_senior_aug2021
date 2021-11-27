// what if I really want the mimimum spanning tree?
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> iPair;

struct edge {
  int w, from, to;
  bool operator<(const edge& e) const {
    return w > e.w;
  }
};
const int SIZE = 11;
const int INF = int(1e9);
int N, M;
vector<iPair> adj[SIZE];

priority_queue<edge> pq; // get the minimum 
bool determined[SIZE]; 
int weights[SIZE];

vector<iPair> adj2[SIZE];

// find the minimum spanning tree
void prim(int start){
  fill(determined, determined+SIZE, false);
  fill(weights, weights+SIZE, INF);
  pq.push({0, -1, start});  // -1 : no from
  weights[start] = 0;
  while(!pq.empty()){
    edge cur = pq.top();
    pq.pop();
    int n = cur.to;
    if(!determined[n]){ // ignore the garbage
      int w = cur.w;
      determined[n] = true;
      if(cur.from != -1){
        adj2[cur.from].push_back({w, n});
      }
      for(iPair next: adj[n]){
        int n2 = next.second;
        if(!determined[n2]){
          int w2 = next.first;
          if(w2 < weights[n2]){
            weights[n2] = w2;
            pq.push({w2, n, n2});
          }
        }
      }
    }
  }
}

int main() {
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({w, b});
    adj[b].push_back({w, a});    
  }
  prim(1);
  // int total_weight = 0;
  // for(int i=1; i<=N; i++) {
  //   total_weight += weights[i];
  //   cout << weights[i] << endl;
  // }
  // cout << "total weights:" << total_weight << endl;
  cout << "-------mst---------" << endl;
  for (int i=1; i<=N; i++){
    for(iPair next : adj2[i]){
      cout << i << " " << next.second << " " << next.first << endl;
    }
  }
}