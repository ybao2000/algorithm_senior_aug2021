#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int h[N+1];
  int w[N];
  for(int i=0; i<N+1; i++) {
    cin >> h[i];
  }
  for(int i=0; i<N; i++){
    cin >> w[i];
  }
  double area = 0;
  for (int i=0; i<N; i++){
    // trapzoidal area = (a+b)*h/2
    area += w[i] * (h[i] + h[i+1])/2.0;
  }
  // cout << fixed << setprecision(1) << area << "\n";
  printf("%.1f\n", area);
}