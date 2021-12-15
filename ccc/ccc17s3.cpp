#include <bits/stdc++.h>

using namespace std;
int pieces[2001]; // I don't want offset, 0, 1:, ...2000:
int boards[4001]; // 2:....4000
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  fill(pieces, pieces+2001, 0); // because not all compiler will initialize with 0
  fill(boards, boards+4001, 0);
  for(int i=0;i <N; i++){
    int a;
    cin >> a;
    pieces[a]++;
  }
  for (int i=1; i<=2000; i++){
    boards[2*i] += pieces[i]/2; // we are accumulating it
    for(int j=i+1; j<=2000; j++){
      boards[i+j] += min(pieces[i], pieces[j]);
    }
  }
  int max_len = 0, ways = 0;
  for(int i=2; i<=4000; i++){
    int len = boards[i];
    if (len > max_len){
      max_len = len;
      ways = 1;
    } else if(len == max_len){
      ways++;
    }
  }
  cout << max_len << " " << ways << "\n";
}