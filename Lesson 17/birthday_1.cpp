#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  if (n > 365) {
    cout << 0 << endl;
  }
  else {
    double p = 1.0;
    for (int i=1; i<n; i++){
      p *= (365.0-i) / 365;
    }
    cout << p << endl;    
  }
}