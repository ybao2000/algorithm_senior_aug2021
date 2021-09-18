#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

double sqr(double x){
  return x*x;
}

int main() {
  const int N = 2000;
  double x[N];
  double y[N];
  int n, r;
  cin >> n >> r;
  cout << fixed << setprecision(10) << endl;
  for(int i=0; i<n; i++){
    cin >> x[i];
    double y_final = r;
    for(int j=0; j<i; j++){
      if(abs(x[i]-x[j]) <= 2 * r){
          double cy = y[j] + sqrt(sqr(2.0*r)-sqr(x[i]-x[j]));
          y_final = max(cy, y_final);
      }
    }
    y[i] = y_final;
    cout << y_final << " ";    
  }
  cout << endl;
}