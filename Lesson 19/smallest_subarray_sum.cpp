// given an array, find the smallest size of subarray that has sum >= target

#include <bits/stdc++.h>

using namespace std;
const int SIZE = 100;
int N;
int a[SIZE];
int target;

int smallest_subarray_sum(){
  int smallest = int(1e9);  // initialize the smallest with a super big number
  int window_start = 0;
  int current_window_sum = 0;
  for(int window_end=0; window_end<N; window_end++){
    current_window_sum += a[window_end];
    while(current_window_sum >= target){  // you reached the condition
      smallest = min(smallest, window_end-window_start+1);
      current_window_sum -= a[window_start];
      window_start++;
    }
  }
  return smallest;
}

int main(){
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> a[i];
  }
  cin >> target;
  cout << smallest_subarray_sum() << "\n";
}