#include <iostream>
using namespace std;

// because int is value type
void add_ten(int &a)    // I manually made a reference type
{
  a = a + 10;
}

int main(){
  int a = 5;
  add_ten(a);
  cout << a << endl;
}