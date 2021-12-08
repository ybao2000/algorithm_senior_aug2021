#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll p = 53;  // prime number
const ll M = 4000004479;  // a super big number

int an[26];
int ah[26];
unordered_set<ll> us;
inline int ord(char c) {return c-'a';}  // simulate python

bool is_permuation(){
  for(int i=0; i<26; i++){
    if (an[i] != ah[i]) return false;
  }
  return true;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string N;
  string H;
  cin >> N;
  cin >> H;
  int len_N = N.length(); // difference length() and size()
  int len_H = H.length();
  if (len_H >= len_N){
    ll hash = 0, power = 1;
    fill(an, an+26, 0);
    fill(ah, ah+26, 0);    
    for (int i=0; i<len_N; i++){
      an[ord(N[i])]++;
      ah[ord(H[i])]++;
      hash = (hash*p + ord(H[i])) % M;
      power = (power * p ) % M;
    }
    for (int i=0; i<=len_H-len_N; i++){
      if (i > 0){
        int a = ord(H[i-1]);  // this is the char to be removed
        int b = ord(H[i+len_N-1]);  // this is the char to be added
        ah[a]--;
        ah[b]++;
        hash = (hash * p + b + a * (M-power)) % M;
      }
      if (is_permuation()) us.insert(hash);
    }
  }
  cout << us.size() << endl;
}