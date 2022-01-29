#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;
int n;
vector<iPair> events;
// first is time, second is type: 1: enter, 2: leave

int main() {
  cin >> n;
  for(int i=0; i<n; i++){
    int a, b;
    cin >> a >> b;
    events.push_back({a, 1});
    events.push_back({b, 2});
  }
  sort(events.begin(), events.end());
  int max_cnt = 0;
  int cnt = 0;
  int first_max_time = 0;
  for(auto event: events){
    if(event.second == 1) { // enter      
      cnt++;
      if(cnt > max_cnt) {
        max_cnt = cnt;
        first_max_time = event.first;
      }
    }
    else {  // leave
      cnt--;
    }
  }
  printf("maximum number of employees: %d\n", max_cnt);
  printf("first time at maximum: %d\n", first_max_time);
}