#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;
typedef pair<int, int> iPair;
const int SIZE = 10001; // add 1 because I don't want offset
const int INF = int(1e9);
int c, r, d;
vector<iPair> adj[SIZE];
unordered_set<int> dests;
priority_queue<iPair> pq; // by default, it will give you the maximum
int weights[SIZE];
bool determined[SIZE];
unordered_set<int> d_dests;

inline int min(int x, int y) { return x < y ? x : y;}

void prim(){  // prim's algorithm to get maximum spanning tree
  fill(determined, determined+SIZE, false);
  fill(weights, weights+SIZE, 0);
  weights[1] = INF;
  pq.push({INF, 1});
  while(!pq.empty()){
    iPair cur = pq.top();
    pq.pop();
    int n = cur.second;
    if(!determined[n]){ // we skip the grabage
      determined[n] = true;
      if(dests.count(n) > 0){ 
        d_dests.insert(n);
        if(d_dests.size() == dests.size()) return; // you can exit if all dests are determined
      }
      for (iPair next: adj[n]){
        int n2 = next.second;
        int w2 = next.first;
        if(!determined[n2]){
          if(w2 > weights[n2]){
            weights[n2] = w2;
            pq.push({w2, n2});
          }
        }
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> c >> r >> d;
  for (int i=0; i<r; i++){ // read the roads
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back({w, y});
    adj[y].push_back({w, x});
  }
  for(int i=0; i<d; i++){ // read the destinations
    int dest;
    cin >> dest;
    dests.insert(dest);
  }
  prim();
  int min_w = INF;
  for(int dest: dests){
    min_w = min(min_w, weights[dest]);    
  }
  cout << min_w << endl;
}
