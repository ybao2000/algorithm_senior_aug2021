#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 1e9;
int letters[100];
int vi[10]; // starting with 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

void print(__int128_t x) {
  if (x > MAX) {
    cout << ll(x/MAX) << ll(x%MAX) << "\n";
  }
  else {
    cout << ll(x) << "\n";
  }
}

int main() {
  int n;
  cin >> n;
  string a, b, c;
  while(n--){
    cin >> a;
    cin >> b;
    cin >> c;
    unordered_set<char> usc;
    for(char ch : a) usc.insert(ch);
    for(char ch : b) usc.insert(ch);
    for(char ch : c) usc.insert(ch);
    vector<char> vc(usc.begin(), usc.end());  // convert the set into a vector
    // counting sort
    for(int i=0; i<vc.size(); i++) letters[vc[i]] = i;
    // init vi
    for(int i=0; i<10; i++) vi[i] = i;
    do {
      if(vi[letters[a[0]]] == 0 || vi[letters[b[0]]] == 0 || vi[letters[c[0]]] == 0) continue;
      __int128_t aa = 0, bb = 0, cc = 0;
      for(char ch: a) aa = aa * 10 + vi[letters[ch]];
      for(char ch: b) bb = bb * 10 + vi[letters[ch]];
      for(char ch: c) cc = cc * 10 + vi[letters[ch]];
      if (aa + bb == cc) {
        // you got it!
        print(aa);
        print(bb);
        print(cc);
        break;
      }
    } while(next_permutation(vi, vi+10));
  }
}