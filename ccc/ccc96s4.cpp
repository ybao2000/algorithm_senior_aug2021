#include <bits/stdc++.h>
using namespace std;

map<int, string> ones = {
  {9, "IX"}, {8, "VIII"}, {7, "VII"}, {6, "VI"}, {5, "V"}, 
  {4, "IV"},{3, "III"}, {2, "II"}, {1, "I"}, {0, ""}};
map<int, string> tens = {
  {9, "XC"}, {8, "LXXX"}, {7, "LXX"}, {6, "LX"}, {5, "L"}, 
  {4, "XL"},{3, "XXX"}, {2, "XX"}, {1, "X"}, {0, ""}};
map<int, string> hundreds = {
  {9, "CM"}, {8, "DCCC"}, {7, "DCC"}, {6, "DC"}, {5, "D"}, 
  {4, "CD"},{3, "CCC"}, {2, "CC"}, {1, "C"}, {0, ""}};  
map<char, int> roman_table = {
  {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
  {'C', 100}, {'D', 500}, {'M', 1000}};

int roman_to_digit(string s){
  int N = s.length();
  if (N == 1) return roman_table[s[0]];
  char c = s[0];
  int cnt = 1; // this is to count the same letter
  int idx = 1;
  int result = 0;
  while (idx < N){
    while (idx < N && s[idx] == c) {
      cnt++;
      idx++;
    }
    if (idx < N) {
      char c2 = s[idx];
      if (roman_table[c2] > roman_table[c]) { // this is a minus
        result -= cnt * roman_table[c];
      }
      else {
        result += cnt * roman_table[c];    
      }
      cnt = 1;
      c = c2;
      idx++;
    }
    if (idx == N) {
        result += cnt * roman_table[c];
    }
  }
  return result;
}

string digit_to_roman(int n){
  if (n == 1000) return "M";
  int m = n / 100;
  n = n % 100;
  string s = hundreds[m];
  m = n / 10;
  n = n % 10;
  return s + tens[m] + ones[n];
}

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    int idx = s.find('+');
    string s1 = s.substr(0, idx);
    string s2 = s.substr(idx+1, s.size()-idx-2);
    // you need a function to convet roman to digit
    int n1 = roman_to_digit(s1);
    int n2 = roman_to_digit(s2);
    if(n1 + n2 > 1000){
      cout << s << "CONCORDIA CUM VERITATE\n";
    }
    else {
      cout << s << digit_to_roman(n1+n2) << "\n";
    }
  }
}