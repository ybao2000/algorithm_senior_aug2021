#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int, int> t4;

int n;
vector<t4> events; // first is x, second is type: 1: enter, 2: vertical, 3: leave
multiset<int> ms;

int main() {
  cin >> n;
  for(int i=0; i<n; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 1) { // horizontal line, b is y, c is x1, d is x2
      events.push_back({c, 1, b, 0});
      events.push_back({d, 3, b, 0});
    }
    else {  // vertical line, b is x, c is y1, d is y2
      events.push_back({b, 2, c, d});
    }
  }
  sort(events.begin(), events.end());
  int cnt = 0;
  for (auto event : events){
    int type = get<1>(event);
    if (type == 1) {
      // enter
      ms.insert(get<2>(event));
    }
    else if (type == 3) {
      // leave
      // ms.erase(get<2>(event)); // don't do this!!! this will erase all duplicates
      ms.erase(ms.find(get<2>(event))); // this is only erasing one element
    }
    else { // vertine segment
      int y1 = get<2>(event);
      int y2 = get<3>(event);
      for(int y: ms) {
        if(y >= y1 && y <= y2) cnt++;
      }
    }
  }
  cout << cnt << "\n";
}