#include <iostream>
using namespace std;

int main(){
  int a = -32;
  int base = -10;
  int rem = a % base;
  int div = a / base;
  cout << "div:" << div << ", rem: " << rem << endl;
}
