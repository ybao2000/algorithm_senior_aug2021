#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100;
int a[SIZE];
int s[SIZE];
int N;

inline int lowbit(int x) {return x & (-x); }

void update(int i, int dx) {  // i is 1-based
  while( i < N+1 ){
    s[i] += dx;
    i += lowbit(i);
  }
}

int query_sum(int i){
  int qs = 0;
  while (i > 0){
    qs += s[i];
    i -= lowbit(i);
  }
  return qs;
}

int range_sum(int i_start, int i_end){
  if (i_start == 0) return query_sum(i_end+1);
  else return query_sum(i_end+1) - query_sum(i_start);
}

int main() {
  cin >> N;
  fill(s, s+N, 0);
  for(int i=0; i<N; i++){
    cin >> a[i];
    update(i+1, a[i]);  // initialize the s-array
  }
  cout << range_sum(1, 5) << endl;
}