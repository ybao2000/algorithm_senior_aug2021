#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> iPair;
const int SIZE = 101;
const int INF = int(1e9);
int N;
unordered_map<string, vector<int>> conns;
unordered_map<string, int> costs;
vector<iPair> adj[SIZE];
bool determined[SIZE];
int weights[SIZE];
priority_queue<iPair, vector<iPair>, greater<iPair>> pq; // you need min

inline int min(int x, int y) {return x < y ? x : y;}
inline int max(int x, int y) {return x > y ? x  : y;}

void build_graph(){
  for(auto conn: conns){
    string xy = conn.first;
    int cost = costs[xy];
    vector<int> pens = conn.second; // size either 1 or 2
    if(pens.size() == 2){
      adj[pens[0]].push_back({cost, pens[1]});
      adj[pens[1]].push_back({cost, pens[0]});
    }
  }
}

void add_outside(){
  for(auto conn: conns){
    string xy = conn.first;
    int cost = costs[xy];
    vector<int> pens = conn.second; // size either 1 or 2
    if(pens.size() == 1){ // this is outside
      adj[pens[0]].push_back({cost, N});
      adj[N].push_back({cost, pens[0]});
    }
  }  
}
void prim(){
  fill(determined, determined+SIZE, false);
  fill(weights, weights+SIZE, INF);
  weights[0] = 0;
  pq.push({0, 0});
  while(!pq.empty()){
    iPair cur = pq.top();
    pq.pop();
    int n = cur.second;
    if(!determined[n]){
      determined[n] = true;
      for(iPair next : adj[n]){
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
int main(){
  cin >> N;
  int t_nodes[10];
  int t_costs[10];
  for(int i=0; i<N; i++){
    int ep;
    cin >> ep;
    for(int k=0; k<ep; k++){
      cin >> t_nodes[k];
    }
    for(int k=0; k<ep; k++){
      cin >> t_costs[k];
    }
    for(int k=0; k<ep; k++){
      int n = (k+1)%ep;
      int a = t_nodes[k];
      int b = t_nodes[n];
      int x = min(a, b);
      int y = max(a, b);
      string xy = to_string(x) + '-' + to_string(y);
      conns[xy].push_back(i);
      costs[xy] = t_costs[k];
    }
  }
  build_graph();
  prim();
  int total_1 = 0;
  for(int i=0; i<N; i++){
    if(weights[i] == INF) { // these means you need outside
      total_1 = INF;
      break;
    }
    total_1 += weights[i];
  }
  add_outside();
  pq = priority_queue<iPair, vector<iPair>, greater<iPair>>();
  prim();
  int total_2 = 0;
  for(int i=0; i<=N; i++){
    total_2 += weights[i];
  }
  cout << min(total_1, total_2) << endl;
}