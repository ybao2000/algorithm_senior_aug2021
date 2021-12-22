#include <bits/stdc++.h>

using namespace std;

// n is the bit numbers
// k is the 1 numbers
void patterns(int n, int k, string aux) {
  if (n == 0) {
    cout << aux << "\n";
    return;
  }
  if (k > 0) patterns(n-1, k-1, aux + "1");
  if (n > k) patterns(n-1, k, aux + "0");
}

int main(){
  int t;
  cin >> t;
  for(int i=0; i<t; i++){
    int n, k;
    cin >> n >> k;
    cout << "The bit patterns are\n";
    patterns(n, k, "");
    if(i < t-1) cout << "\n";
  }
}