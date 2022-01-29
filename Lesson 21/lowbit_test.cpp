#include <bits/stdc++.h>
using namespace std;

int lowbit(int a){
  return a & (-a);
}

int main() {
  int a= 13;
  cout << lowbit(a) << endl;
}