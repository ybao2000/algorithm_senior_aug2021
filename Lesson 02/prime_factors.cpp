#include <iostream>
#include <map>
using namespace std;

// define a function which takes the number, and return a map
map<int, int> get_factors(int n){
  map<int, int> map1;
  for(int i=2; i*i <= n; i++){
    int ic=0; // count
    while(n%i==0){
      ic++;
      n /= i;
    }
    if(ic > 0){
      map1[i] = ic;
    }
  }
  if (n>1){
    map1[n] = 1;
  }
  return map1;
}

int main(){
  int n = 2023;
  map<int, int> m = get_factors(n);
  if (m.size() == 0){
    cout << "it's a prime" << endl;
  }
  else {
    for(auto pair : m){
      cout << pair.first << ":" << pair.second << endl;
    }
  }
}