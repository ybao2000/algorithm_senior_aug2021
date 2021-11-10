#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> iPair;
const int SIZE = 5001; // we don't need offset of 0
const int INF = int(1e9); 
int N, T, K;
vector<iPair> adj[SIZE];  // a big array 
int prices[SIZE];         // this is the price of the shops
// we need 3 more things
bool visited[SIZE];
int costs[SIZE];          // this is going to be the transportation cost
priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

inline int min(int x, int y) {return x < y ? x : y;}

void dijkstra(int dest){
  // this is to calculate the minimum cost for all nodes
  fill(costs, costs+SIZE, INF);
  fill(visited, visited+SIZE, false);
  // dijkstra's algorithm is very similar to BFS
  pq.push({0, dest}); // first is the cost, second is the node
  costs[dest] = 0;
  while(!pq.empty()){
    iPair cur = pq.top();
    pq.pop();
    int c = cur.first;
    int n = cur.second;
    visited[n] = true;
    for(iPair edge : adj[n]){
      // get the routes for the node n
      int n2 = edge.second;
      if(!visited[n2]) {
        int c2 = c + edge.first;
        if (c2 < costs[n2]) {
          costs[n2] = c2;
          pq.push({c2, n2});
        }
      }
    }
  }

}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  cin >> T;
  for(int i=0; i<T; i++){
    // we need adjacency list
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back({w, y});
    adj[y].push_back({w, x});
  }
  // make all prices INF
  fill(prices, prices+SIZE, INF); // this is to make price super big
  cin >> K;
  for(int i=0; i<K; i++){
    int x, p;
    cin >> x >> p;
    prices[x] = p;
  }
  int dest;
  cin >> dest;
  dijkstra(dest);
  int min_total = INF;
  for(int i=1; i<=N; i++){
    min_total = min(min_total, prices[i] + costs[i]);
  }
  cout << min_total << endl;
}