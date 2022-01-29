#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;
const int INF = 2e9;
int R, C;
int pr, pc, kr, kc;
queue<iPair> q;
int grid[100][100];
bool visited[100][100];

inline bool is_valid(iPair loc) {
  return loc.first >= 0 && loc.first < R  && loc.second >= 0 && loc.second < C;
}

iPair next_step(iPair loc, int k) {
  switch(k) {
    case 0: return {loc.first+2, loc.second+1};
    case 1: return {loc.first+1, loc.second+2};
    case 2: return {loc.first-1, loc.second+2};
    case 3: return {loc.first-2, loc.second+1};
    case 4: return {loc.first-2, loc.second-1};
    case 5: return {loc.first-1, loc.second-2};
    case 6: return {loc.first+1, loc.second-2};
    default: return {loc.first+2, loc.second-1};
  }
}

int main() {
  int n;
  cin >> n;
  while(n--) {
    cin >> R;
    cin >> C;
    cin >> pr;
    cin >> pc;
    cin >> kr;
    cin >> kc;
    pr--, pc--, kr--, kc--; // make it 0-based
    q = queue<iPair>(); // clean up
    fill(&grid[0][0], &grid[0][0]+10000, INF);
    fill(&visited[0][0], &visited[0][0]+10000, false);
    // start from the {kr, kc} knight
    grid[kr][kc] = 0; 
    q.push({kr, kc});
    visited[kr][kc] = true;
    while (!q.empty()) {
      iPair loc = q.front();
      q.pop();
      for(int k=0; k<8; k++){
        iPair loc_next = next_step(loc, k);
        if(is_valid(loc_next) && !visited[loc_next.first][loc_next.second]) {
          grid[loc_next.first][loc_next.second] = grid[loc.first][loc.second] + 1;
          q.push(loc_next);
          visited[loc_next.first][loc_next.second] = true;
        }
      }
    }
    int win = INF; // the steps to win
    int stale = INF;  // the steps to stalemate
    for(int j=pr; j<R-1; j++) {
      int step = j-pr;  // the step of the pawn
      if (grid[j][pc] == step || (grid[j][pc] < step && (step-grid[j][pc]) % 2 == 0)){
        win = step;
        break;
      }
      else if (stale == INF && 
      (grid[j+1][pc] == step || (grid[j+1][pc] < step && (step-grid[j+1][pc]) % 2 == 0))) {
        stale = step;
      }
    }
    if (win < INF) {
        printf("Win in %d knight move(s).\n", win);
    } else if (stale < INF) {
      printf("Stalemate in %d knight move(s).\n", stale);
    } else {
      printf("Loss in %d knight move(s).\n", R-2-pr);
    }
  }
}