#include <iostream>
#include <vector>
using namespace std;

vector<int> calc_distinct_primes(int n){
  vector<int> primes;
  // just iterate from 2 to sqrt(n)
  // we can accelerate the process
  // we calculate 2 first
  int ic = 0;
  while(n % 2 == 0) {
    ic++;
    n = n/2;
  }
  if (ic>0){
    primes.push_back(2);
  }
  for(int i=3; i*i<=n; i+=2){ // always odd
    ic = 0;
    while(n%i==0){
      ic++;
      n = n / i;
    }
    if(ic > 0){
      primes.push_back(i);
    }
  }
  if(n>1){
    primes.push_back(n);
  }
  return primes;
}

// to calculate the totient function
int calc_phi(int n){
  // first, you need to find all distinct primes
  vector<int> primes = calc_distinct_primes(n);
  int phi = n;
  for(auto prime: primes){
    phi = phi / prime * (prime-1);
  }
  return phi;
}

// n is not prime
// a and n are co-prime 
// usually n is small (thousand maybe is ok, but million maybe too big)
int get_mod(int a, int k, int n){
  // you need to caulate the totient function
  int phi = calc_phi(n);
  int rem = k % phi;
  int result = 1;
  for(int i=0; i<rem; i++){
    result = (result * a) % n;  // don't forget to mod
  }
  return result;
}

int main(){
  int a = 3;
  int k = 1e9+7;
  int n = 2021;
  cout << get_mod(a, k, n) << endl;

  // test distinct prime factors

  // vector<int> v = calc_distinct_primes(120);
  // for(auto num : v){
  //   cout << num << endl;
  // }
  // cout << calc_phi(60);
}