#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 11;
const int INF = int(1e9);
int N, M;
int adj[SIZE][SIZE];

int sum(int a, int b){
  if (a == INF || b == INF){
    return INF;
  }
  else return a + b;
}

void floyd() {
  for(int k=1; k<=N; k++){
    for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
        if(i != k && j != k){
          adj[i][j] = min(adj[i][j], sum(adj[i][k], adj[k][j]));
        }
      }
    }
  }
}
int main(){
  cin >> N >> M;
  fill(*adj, *adj+SIZE*SIZE, INF);
  for(int i=0; i<N; i++) adj[i][i] = 0;
  for(int i=0; i<M; i++){
    int a, b, d;
    cin >> a >> b >> d;
    adj[a][b] = d;
  }
  floyd();
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      if(adj[i][j] == INF) {
        cout << -1 << " ";
      }
      else {
        cout << adj[i][j] << " ";
      }
    }
    cout << endl;
  }  
}