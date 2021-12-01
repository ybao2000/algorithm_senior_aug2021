#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;
typedef pair<int, int> iPair;
const int SIZE = 200001;  // 1 for offset
const int INF = int(1e9);
int N, W, D;
vector<int> adj[SIZE];
queue<int> q;
bool visited[SIZE];
int levels[SIZE];
int S[SIZE];
set<iPair> dists; // this is going to store station seqNo + levels, station name

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
    if (levels[S[i]] != INF) {  // forget about those no-path
      dists.insert({levels[S[i]]+i, S[i]});
    }  
  }

  for (int i=0; i<D; i++) {
    int a, b;
    cin >> a >> b;
    dists.erase({levels[S[a]]+a, S[a]});
    dists.erase({levels[S[b]]+b, S[b]});
    swap(S[a], S[b]);
    dists.insert({levels[S[a]]+a, S[a]});
    dists.insert({levels[S[b]]+b, S[b]});    
    cout << (*dists.begin()).first-1 << endl;
  }
}