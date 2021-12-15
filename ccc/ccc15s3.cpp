#include <bits/stdc++.h>

using namespace std;
const int SIZE = 1e5+1;
int G, P;
bool gates[SIZE];

int find_max_gate(int g){
  int idx = g;
  while(gates[idx]) idx--;
  return idx;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> G;
  cin >> P;
  fill(gates, gates+SIZE, false);
  int cnt = 0;  
  for(int i=0; i<P; i++){
    int g;
    cin >> g;
    int x = find_max_gate(g);
    if (x < 1) break; // game over
    else {
      cnt++;
      gates[x] = true;
    }
  }
  cout << cnt << "\n";
}