#include <iostream>
using namespace std;

int main(){
  int t;
  cin >> t;
  for(int i=0; i<t; i++){
    int zero_number;
    cin >> zero_number;
    int min_digit;
    int min_number = 1e6;
    int number;
    for (int j=1; j<10; j++){
      cin >> number;
      if (number < min_number) {
        min_digit = j;
        min_number = number;
      }
    }
    if (zero_number < min_number){
      cout << 1;
      for(int k=0; k<=zero_number; k++){
        cout << 0;
      }
      cout << endl;
    }
    else{
      for(int k=0; k<=min_number; k++){
        cout << min_digit;
      }
      cout << endl;
    }
  }
}
