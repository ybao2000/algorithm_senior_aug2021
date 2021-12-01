#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int SIZE = 200001;  // 1 for offset
const int INF = int(1e9);
int N, W, D;
vector<int> adj[SIZE];
queue<int> q;
bool visited[SIZE];
int levels[SIZE];
int S[SIZE];
int dists[SIZE];

void bfs() {
  fill(visited, visited+SIZE, false);
  fill(levels, levels+SIZE, INF); // INF means no path
  q.push(N);
  visited[N] = true; // whenever you do the push, update visited, and levels
  levels[N] = 0;
  while (!q.empty()){
    int cur = q.front();
    q.pop();
    for(int sub : adj[cur]){
      if (!visited[sub]){
        q.push(sub);
        visited[sub] = true;
        levels[sub] = levels[cur] + 1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);  
  cin >> N >> W >> D;
  for(int i=0; i<W; i++){
    int a, b;
    cin >> a >> b;
    adj[b].push_back(a); // because you wills start from N
  }
  bfs();
  for (int i=1; i<=N; i++){
    cin >> S[i];    
  }

  for (int i=0; i<D; i++) {
    int a, b;
    cin >> a >> b;
    swap(S[a], S[b]);
    int min_time = INF;
    for(int k=1; k<=N; k++){
      min_time = min(min_time, levels[S[k]]+k-1);
    }
    cout << min_time << endl;
  }
}