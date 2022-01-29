#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100;
int a[SIZE];
int s[SIZE];  // prefix sum array
int N;

// sum up the items from index i to index j
// int query_sum(int i_start, int i_end){
//   int s = 0;
//   for(int i=i_start; i<=i_end; i++) {
//     s += a[i];
//   }
//   return s;  
// }

int query_sum(int i_start, int i_end){
  if (i_start == 0) return s[i_end];
  else {
    return s[i_end] - s[i_start-1];
  }
}

int main() {
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> a[i];
  }
  s[0] = a[0];
  for(int i=1; i<N; i++){
    s[i] = s[i-1]+ a[i];
  }
  cout << query_sum(1, 5);
}