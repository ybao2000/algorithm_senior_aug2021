#include <bits/stdc++.h>
using namespace std;

const int INF = int(2e9);
int N;
struct section {
  int nA=0, nB=0, nC=0;
  void add(char letter){
    if (letter == 'A') nA++;
    else if(letter=='B') nB++;
    else nC++;
  }
  void remove(char letter) {
    if (letter == 'A') nA--;
    else if(letter=='B') nB--;
    else nC--;
  }
};

int solve(string s){
  section total, SA, SB, SC;
  for(int i=0; i<N; i++) {
    total.add(s[i]);
  }
  int idx = 0;
  for(int i=0; i<total.nA; i++){  // A-section
    SA.add(s[idx]);
    idx++;
  }
  for(int i=0; i<total.nB; i++){  // B-section
    SB.add(s[idx]);
    idx++;
  }
  for(int i=0; i<total.nC; i++){  // C-section
    SC.add(s[idx]);
    idx++;
  }
  int min_swaps = INF;
  for(int i=0; i<N; i++){
    int swap = SA.nB + SA.nC + SB.nA + SB.nC - min(SA.nB, SB.nA);
    min_swaps = min(min_swaps, swap);
    // sliding window
    SA.remove(s[i]);
    SA.add(s[i+total.nA]);
    SB.remove(s[i+total.nA]);
    SB.add(s[i+total.nA+total.nB]);
    SC.remove(s[i+total.nA+total.nB]);
    SC.add(s[i+total.nA + total.nB + total.nC]);
  }
  return min_swaps;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  N = s.length();
  s += s; // double the string to make your life easy
  int answer = solve(s);
  for(size_t i=0; i<s.length(); i++){
    // swap B with C
    if(s[i] == 'B') s[i] ='C';
    else if(s[i] == 'C') s[i] = 'B';
  }
  answer = min(answer, solve(s));
  cout << answer << endl;
}
