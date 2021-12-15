#include <bits/stdc++.h>
using namespace std;

int G, P;
set<int> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> G;
  cin >> P;  
  // init the set
  for(int i=1; i<=G; i++) s.insert(i);  // insert all gates
  int cnt = 0;
  for(int i=0; i<P; i++){
    int g;
    cin >> g;
    auto x = s.lower_bound(g); // this is going to give you the first pointer >= g
    if (*x == g) { // this means set has it
      cnt++;
      s.erase(x);
    } else if(x != s.begin()){ // this means you didn't find it
      x--;  // decrease the pointer
      cnt++;
      s.erase(x);
    } else {  // game over
      break;
    }
  }
  cout << cnt << "\n";  
}