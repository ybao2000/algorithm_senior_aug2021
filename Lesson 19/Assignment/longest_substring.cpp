// Write a function to find the longest substring 
// with no more than k distinct characters. 
// If there are more, just return the first one.

// string longest_substring(string s, int k)

// example:

// longest_substring("abacedefabacabcd ", 3) =>  “abacabc”

// you can test your function at lintcode

// https://www.lintcode.com/problem/386/

#include <bits/stdc++.h>

using namespace std;

int longest_substring(string s, int k){
  if (s.length() == 0 || k == 0) return 0;
  int window_start = 0;
  unordered_map<char, int> repo; // this is to store the char and its occurence
  int start = 0, end = 0; // this will be the solution
  for (int window_end=0; window_end<s.length(); window_end++){ // this is moving the head
    char c = s[window_end];
    if (repo.find(c) == repo.end()){  // c is not in the repo yet
      repo[c] = 1;
    } else {
      repo[c]++;
    }
    while(repo.size() > k) {  // it means you have move your tail
      char c2 = s[window_start];
      if(repo[c2] > 1) repo[c2]--;  // you have more than 1 occurence
      else repo.erase(c2);
      window_start++;
    }
    if (window_end - window_start > end - start) {
      end = window_end;
      start = window_start;
    }
  }
  return end-start+1;
}

int main() {

  string s;
  cin >> s;
  int k;
  cin >> k;
  cout << longest_substring(s, k) << "\n";
}