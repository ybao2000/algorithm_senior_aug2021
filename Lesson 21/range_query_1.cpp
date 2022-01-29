#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100;
int a[SIZE];
int N;

// sum up the items from index i to index j
int query_sum(int i_start, int i_end){
  int s = 0;
  for(int i=i_start; i<=i_end; i++) {
    s += a[i];
  }
  return s;  
}

int main() {
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> a[i];
  }
  cout << query_sum(1, 5);
}