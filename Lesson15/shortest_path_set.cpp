#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> iPair;

const int SIZE = 11;
const int INF = int(1e9); // INF + INF
int N, M;
vector<iPair> adj[SIZE];

// priority_queue<iPair> pq; // this is to give you the maximum
set<iPair> pq; // get the minimum 
bool determined[SIZE]; 
int weights[SIZE];

// find the shortest path for all other nodes
void dijkstra(int start){
  fill(determined, determined+SIZE, false);
  fill(weights, weights+SIZE, INF);
  pq.insert({0, start});
  // whenever you do the push, update the weights
  weights[start] = 0;
  while(!pq.empty()){
    iPair cur = *(pq.begin());  // this is to get the item with minimum weight
    pq.erase(pq.begin());
    int n = cur.second;
    int w = cur.first;
    determined[n] = true;
    for(iPair next: adj[n]){
      int n2 = next.second;
      if(!determined[n2]){ // not determined
        int w2 = w + next.first;
        if(w2 < weights[n2]){
          if(pq.find({weights[n2], n2}) != pq.end()){
            pq.erase({weights[n2], n2});
          }
          weights[n2] = w2;
          pq.insert({w2, n2});
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
  dijkstra(1);
  for(int i=1; i<=N; i++){
    cout << weights[i] << endl;
  }
}