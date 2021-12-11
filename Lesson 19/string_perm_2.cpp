#include <bits/stdc++.h>

using namespace std;

int main(){
  string a;
  cin >> a;
  do {
    cout << a << "\n";
  } while (next_permutation(a.begin(), a.end()));
}