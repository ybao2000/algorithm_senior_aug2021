#include <iostream>
using namespace std;
int n1 = 1, n2 = 2, n3 = 3, n4 = 4; // global: avaialbe to any function

void h_flip(){
  // int t = n1;
  // n1 = n3;
  // n3 = t;
  // t = n2;
  // n2 = n4;
  // n4 = t;
  swap(n1, n3);
  swap(n2, n4);
}

void v_flip(){
  // int t = n1;
  // n1 = n2;
  // n2 = t;
  // t = n3;
  // n3 = n4;
  // n4 = t;
  swap(n1, n2);
  swap(n3, n4);
}

int main(){
  string s;
  cin >> s;
  for (char c: s){
    if( c == 'H') {
      h_flip();
    }
    else {
      v_flip();
    }
  }
  cout << n1 << " " << n2 << endl;
  cout << n3 << " " << n4 << endl;
}