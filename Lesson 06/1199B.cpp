#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  double H, L;   // why int doesn't work?
  cin >> H >> L;
  double x = (L*L-H*H)/(2.0*H);
  cout << fixed << setprecision(10) << x << endl;   
}