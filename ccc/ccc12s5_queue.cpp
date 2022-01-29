#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
int R, C, K;
int grid[25][25]; // same as dp, total different ways
bool visited[25][25];   // you need visited
queue<iPair> q;

inline int is_valid(iPair loc) {
  return loc.first >= 0 && loc.first < R && loc.second >= 0 && loc.second < C;
}

iPair next_loc(iPair loc, int dir) {
  switch(dir) {
    case 0: return {loc.first, loc.second+1}; // right
    case 1: return {loc.first+1, loc.second}; // down
    case 2: return {loc.first, loc.second-1}; // left
    default: return {loc.first-1, loc.second}; // up
  }
}

int main() {
  fill(&grid[0][0], &grid[0][0]+625, 0);
  fill(&visited[0][0], &visited[0][0]+625, false);
  cin >> R >> C;
  cin >> K;
  for(int i=0; i<K; i++){
    int r, c;
    cin >> r >> c;
    grid[r-1][c-1] = 0; // no way for cats
    visited[r-1][c-1] = true; // mark cats as visited
  }
  // queue, always to 3 things
  // set the value
  // push it into queue
  // make it visited
  grid[0][0] = 1; // start
  q.push({0, 0});
  visited[0][0] = true;
  while(!q.empty()) {
    iPair loc = q.front();
    q.pop();
    iPair loc_right = next_loc(loc, 0); 
    if (is_valid(loc_right) && !visited[loc_right.first][loc_right.second]) {
      q.push(loc_right);
      visited[loc_right.first][loc_right.second] = true;
    }
    iPair loc_left = next_loc(loc, 1);
    if(is_valid(loc_left) && !visited[loc_left.first][loc_left.second]) {
      q.push(loc_left);
      visited[loc_left.first][loc_left.second] = true;
    }
    // calculate the grid for loc
    if(!(loc.first == 0 && loc.second == 0)) {  // skip the first cell
      int cnt = 0;
      iPair loc_left = next_loc(loc, 2);
      if(is_valid(loc_left)) cnt += grid[loc_left.first][loc_left.second];
      iPair loc_up = next_loc(loc, 3);
      if(is_valid(loc_up)) cnt += grid[loc_up.first][loc_up.second];
      grid[loc.first][loc.second] = cnt;
    }
  }
  cout << grid[R-1][C-1] << "\n";
}