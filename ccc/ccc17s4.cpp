#include <bits/stdc++.h>
using namespace std;
struct edge {
  int from, to, cost, type; // type: 1 active, 2 inactive
};
const int SIZE = 1e5+2;

bool compare_edge(const edge &a, const edge &b) {
  if (a.cost != b.cost) return a.cost < b.cost;
  else return a.type < b.type;  // active first for the same cost
}

int N, M, D;
vector<edge> edges;
int root[SIZE];
int days, mst_max_cost;  

// recursive, and when you are looking for the root
// you immediately update the root
int find(int x) {
    if (x == root[x])
        return x;
    return root[x] = find(root[x]);  // c syntax, when you are returning an assign statement
}

void unite(int a, int b){
  a = find(a);
  b = find(b);
  if (a != b) root[b] = a;
}

// generate the minimum spanning tree
void kruskal() {
  // init the root
  for(int i=0; i<N; i++) root[i] = i;
  days = 0, mst_max_cost = 0;
  for(int i=0; i<M; i++) {
    edge e = edges[i];
    if(find(e.from) != find(e.to)){
      unite(e.from, e.to);
      if (e.type == 2) days++;
      mst_max_cost = max(mst_max_cost, e.cost);
    }
  }
}

void kruskal_2() {
  // init the root
  for(int i=0; i<N; i++) root[i] = i;
  for(int i=0; i<M; i++) {
    edge e = edges[i];
    if(find(e.from) != find(e.to)){
      if (e.cost < mst_max_cost){
        unite(e.from, e.to);
      }
      else if(e.type == 1) { // active one
        if (e.cost == mst_max_cost) {
          unite(e.from, e.to);
        } else if(e.cost <= D) {  // you find it, which can reduce the day
          days--;
          return;
        }
      }
    }
  }
}

int main() {
  // these 2 lines are saving time
  // if you have big input
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> D;
  for (int i=0; i<M; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--; // zero-based
    edges.push_back({a, b, c, i < N-1 ? 1: 2 });
  }
  sort(edges.begin(), edges.end(), compare_edge);
  kruskal();
  // for D > 0, try to find an active edge which can replace an inactive edge (always the max cost in MST)
  // D is always to reduce the max cost in the MST
  // and the reduced cost is min(0, max_cost-D)
  // if there exists such an edge not in MST 
  // that can be swapped in to reduce the day (the original reduced total cost is already optimal)
  // it must be active and its cost > mst_max_cost
  // but its cost should be <= D (otherwise, the reduced total cost cannot be kept), 
  // so that active edge can be swapped in
  // mst_max_cost < cost <= D  
  if(mst_max_cost < D && N > 2){
    kruskal_2();
  }
  cout << days << '\n';
}