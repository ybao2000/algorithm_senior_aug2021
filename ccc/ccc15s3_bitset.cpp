#include <bits/stdc++.h>

using namespace std;
int G, P;
bitset<100001> gates;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> G;
  cin >> P;
  gates.flip(); // initial make all of them 1 (ok, valid)
  int cnt = 0;
  for (int i=0; i<P; i++){
    int g;
    cin >> g;
    int idx = gates._Find_next(G-g);
    if (idx > G) break; // game over
    else {
      gates[idx] = 0;
      cnt++;
    }
  }
  cout << cnt << "\n";
}