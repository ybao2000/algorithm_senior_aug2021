#include <bits/stdc++.h>

using namespace std;

// you need auxiliary string
// loop through each element
// and appending the element to the ans
// then recursively call for the remaining
void permute(string a, string ans){
  if (a.length() == 0){
    cout << ans << "\n";
    return;
  }
  for(int i=0; i<a.length(); i++){
    char c = a[i]; // put c to the end of ans
    string left = a.substr(0, i);
    string right = a.substr(i+1);
    string rest = left + right;
    permute(rest, ans + c);
  }
}

int main() {
  string a;
  cin >> a;
  permute(a, "");
}