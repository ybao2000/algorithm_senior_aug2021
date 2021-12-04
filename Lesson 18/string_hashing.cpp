#include <bits/stdc++.h>  // g++ allows this head file

using namespace std;
typedef long long ll;

ll hash_1(string s){
  ll p = 31; // or 53
  ll m = int(1e9+7); // a big # 
  ll sum = 0;
  ll q = p;
  for (char c : s){ 
    int a = c - 'a' + 1;  // you want to skip 0
    sum  = (sum + a * q) % m;
    q = (q * p ) % m;
  }
  return sum;
}

ll hash_2(string s){
  ll p = 31;
  ll m = int(1e9+7);
  ll sum = 0;
  ll q = p;
  for (int i=s.length()-1; i>=0; i--){
    int a = s[i]-'a' + 1;
    sum  = (sum + a * q) % m;
    q = (q * p ) % m; 
  }
  return sum;
}
int main() {
  string s;
  cin >> s;
  cout << hash_1(s) << endl;
  cout << hash_2(s) << endl;
}