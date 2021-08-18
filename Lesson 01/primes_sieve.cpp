#include <bits/stdc++.h>
using namespace std;

// using the algorithm called sieve of eratosthenes
vector<int> primes_sieve(int n){
  // bool marks[n+1] = {true};
  // how to make all true?
  bool marks[n+1];
  fill_n(marks, n+1, true);
  for(int i=2; i*i<=n; i++){
    if(marks[i]) {
      // for all i (prime), cross out all multiples of i
      for(int j=i*2; j<=n; j+=i){
        marks[j] = false;
      }
    }
  }
  vector<int> vi;
  for(int i=2; i<=n; i++){
    if(marks[i]) vi.push_back(i);
  }
  return vi;
}

int main(){
  int n = 20;
  for(auto p : primes_sieve(n)){
    cout << p << " ";
  }
  cout << endl;
}
