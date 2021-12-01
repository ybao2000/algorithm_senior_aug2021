#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 100000;

int N, M;
bool dests[SIZE]; // to distiguish destination from non-destination
vector<int> adj[SIZE];
int max_dist; // this is to store the maximum dist
int max_r;    // this is to store the farthest dest rest
// recursive function
void trim(int node, int from){
  for (int next: adj[node]){
    if (next == from) continue; 
    trim(next, node); // iterative call
    if (dests[next]) {
      if(!dests[node]){
        dests[node] = true;
        M++;
      }
    }
  }
}

void dfs(int node, int from, int dist){
  if (dist > max_dist) {
    max_dist = dist;
    max_r = node;
  }
  for (int next: adj[node]){
    if (next == from) continue;
    if(dests[next]){  // skip all non-dests
      dfs(next, node, dist+1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0); 
  cin >> N >> M;
  int pho;  
  for (int i=0; i<M; i++){
    cin >> pho;
    dests[pho] = true;
  }
  for(int i=0; i<N-1; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  trim(pho, -1);
  max_dist = 0;
  dfs(pho, -1, 0);
  max_dist = 0; // don't forget to reset it
  dfs(max_r, -1, 0);
  cout << 2 * (M-1) - max_dist << endl;
}