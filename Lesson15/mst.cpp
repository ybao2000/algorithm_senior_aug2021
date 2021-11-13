#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> iPair;

const int SIZE = 11;
const int INF = int(1e9);
int N, M;
vector<iPair> adj[SIZE];

priority_queue<iPair, vector<iPair>, greater<iPair>> pq; // get the minimum 
bool determined[SIZE]; 
int weights[SIZE];

// find the minimum spanning tree
void prim(int start){
  fill(determined, determined+SIZE, false);
  fill(weights, weights+SIZE, INF);
  pq.push({0, start});
  weights[start] = 0;
  while(!pq.empty()){
    iPair cur = pq.top();
    pq.pop();
    int n = cur.second;
    if(!determined[n]){ // ignore the garbage
      int w = cur.first;
      determined[n] = true;
      for(iPair next: adj[n]){
        int n2 = next.second;
        if(!determined[n2]){
          int w2 = next.first;
          if(w2 < weights[n2]){
            weights[n2] = w2;
            pq.push({w2, n2});
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
  int total_weight = 0;
  for(int i=1; i<=N; i++) {
    total_weight += weights[i];
    cout << weights[i] << endl;
  }
  cout << "total weights:" << total_weight << endl;
}