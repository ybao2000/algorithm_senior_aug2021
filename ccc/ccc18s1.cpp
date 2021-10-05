#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

double min(double a, double b) {return a < b ? a : b;}
int main(){
  int N;
  cin >> N;
  int V[N];
  for (int i=0; i<N; i++){
    cin >> V[i];
  }
  sort(V, V+N);
  double min_neignbor = 1e18;
  for (int i=1; i<N-1; i++){
    min_neignbor = min(min_neignbor, (V[i+1]-V[i-1])/2.0); 
  }
  cout << fixed << setprecision(1) << min_neignbor << endl;
}