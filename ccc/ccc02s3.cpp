#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;

const int MAX_R = 375;
const int MAX_C = 80;
int r, c;
char grid[MAX_R][MAX_C];
int m;
char instructions[30000];
// the first trick is using set instead of vector
set<iPair> path;
iPair dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main(){
  cin >> r >> c;
  for (int i=0; i<r; i++){
    for(int j=0; j<c; j++) {
      cin >> grid[i][j];
    }
  }
  cin >> m;
  for(int i=0; i<m; i++){
    cin >> instructions[i];
  }
  for (int d = 0; d < 4; d++){  // try 4 directions
    path.clear();
    int dir = d;
    iPair loc = {0, 0};
    path.insert(loc);
    for(int i=0; i<m; i++){
      if (instructions[i] == 'F') { // go forward
        loc = {loc.first + dirs[dir].first, loc.second + dirs[dir].second};
        path.insert(loc);
      }
      else if(instructions[i] == 'R') { // turn right
        dir = (dir+1)%4;
      }   
      else  {
        dir = (dir+3)%4;
      }
    }
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        bool valid = true;
        for(iPair loc2: path){
          // need to check 2 things: 1. is it out-of-boundary, 2. it is an X
          int row = loc2.first + i;
          int col = loc2.second + j;
          if ((row < 0 || row >= r ) || (col < 0 || col >= c) || grid[row][col] == 'X') {
            valid = false;
            break;
          }
        }
        if(valid) {
          grid[loc.first+i][loc.second+j] = '*';
        }
      }
    }
  }
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cout << grid[i][j];
    }
    cout << "\n";
  }
}