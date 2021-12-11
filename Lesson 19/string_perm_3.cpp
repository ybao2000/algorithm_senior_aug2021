#include <bits/stdc++.h>

using namespace std;
string a;
int n;
void permute(int idx) {
  if (idx == n-1) {
    cout << a << "\n";
    return;
  }   
  for (int i=idx; i<n; i++){
    swap(a[idx], a[i]);
    permute(idx+1);
    swap(a[idx], a[i]);
  }

}

int main() {
  cin >> a;
  n = a.length();
  permute(0);
}