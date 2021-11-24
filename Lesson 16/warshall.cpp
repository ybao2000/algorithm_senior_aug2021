#include <iostream>
#include <memory>
using namespace std;
const int SIZE = 10;
int N, M;
int adj[SIZE][SIZE];

void warshall(){
  for(int k=0; k<N; k++){
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(i != k && j != k){
          adj[i][j] = adj[i][j] | (adj[i][k] & adj[k][j]);
        }
      }
    }
  }
}
int main(){
  cin >> N >> M;
  // how to fill 2d Array?
  fill(&adj[0][0], &adj[0][0]+SIZE*SIZE, 500000);
  //memset(adj, 500000, SIZE*SIZE*sizeof(int)); // this is to fill with the bytes
  for(int i=0; i<N; i++) adj[i][i] = 1;
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    adj[a-1][b-1] = 1;
  }
  warshall();
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }
}