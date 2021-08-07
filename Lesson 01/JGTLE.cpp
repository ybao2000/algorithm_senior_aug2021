#include <iostream>
using namespace std;

typedef long long ll;
int main(){
  int t;
  cin >> t;
  for(int tc=1; tc<=t; ++tc){
    int a, b, c;
    cin >> a >> b >> c;
    ll result = 0;
    ll sb = b * (b+1)/2;
    ll sc = c * (c+1)/2;
    result = a * sb * sc;
    cout << "Case " << tc << ": " << result << endl;
  }
}