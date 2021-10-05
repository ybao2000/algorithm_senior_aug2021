#include <iostream>

using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  int A[N], B[N];
  for (int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=0; i<N; i++){
    cin >> B[i];
  }
  int K = 0;
  ll total1=0, total2 = 0;
  for(int i=0; i<N; i++){
    total1 += A[i];
    total2 += B[i];
    if (total1 == total2){
      K = i+1;
    }
  }
  cout << K << endl;
}