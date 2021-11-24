#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> iPair;

const int SIZE = 100;
int N, M;
char grid[SIZE][SIZE];
vector<iPair> cameras;
iPair start;
bool forbidden[SIZE][SIZE]; // use cameras to derive the forbidden
bool visited[SIZE][SIZE];
queue<iPair> q;
int steps[SIZE][SIZE];  // this is going to be the result
iPair dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(iPair start){
  fill(*visited, *visited+SIZE*SIZE, false);
  fill(*steps, *steps+SIZE*SIZE, -1);
  if(forbidden[start.first][start.second]) return;
  q.push(start); // everytime when you push, make it visited
  visited[start.first][start.second] = true;
  steps[start.first][start.second] = 0;
  while(!q.empty()){
    iPair loc = q.front();
    q.pop();
    int r = loc.first;
    int c = loc.second;
    for (int i=0; i<4; i++) {
      int r2 = r + dirs[i].first;
      int c2 = c + dirs[i].second;
      while(true) {
        if (visited[r2][c2]) break;
        if(grid[r2][c2] == 'U'){
          visited[r2][c2] = true;
          r2--;
        }
        else if(grid[r2][c2] == 'D'){
          visited[r2][c2] = true;
          r2++;
        }
        else if(grid[r2][c2] == 'L'){
          visited[r2][c2] = true;          
          c2--;
        }
        else if(grid[r2][c2] == 'R'){
          visited[r2][c2] = true;          
          c2++;
        }
        else {
          break;
        }
      }
      if (r2 >= 0 && r2 < N && c2 >= 0 && c2 < M
      && !visited[r2][c2] && !forbidden[r2][c2] 
      && grid[r2][c2] == '.'){
        q.push({r2, c2});
        visited[r2][c2] = true;
        steps[r2][c2] = steps[r][c]+ 1;
      }
    }
  }
}

void check_cameras(){
  for (iPair cam : cameras){
    int row = cam.first;
    int col = cam.second;
    forbidden[row][col] = true;
    for (int i=col-1; i>=0; i--){ // left
      if (grid[row][i] == 'W') break;
      else if (grid[row][i] == '.' || grid[row][i] == 'S') {
        forbidden[row][i] = true;
      }
    }
    for (int i=col+1; i<M; i++){   // right
       if (grid[row][i] == 'W') break;
        else if (grid[row][i] == '.' || grid[row][i] == 'S') {
        forbidden[row][i] = true;
      }     
    }
    for (int i=row-1; i>=0; i--){ // up
      if(grid[i][col] == 'W') break;
      else if (grid[i][col] == '.' || grid[i][col] == 'S') {
        forbidden[i][col] = true;
      }
    }
    for (int i=row+1; i<N; i++){
      if(grid[i][col] == 'W') break;
      else if (grid[i][col] == '.' || grid[i][col] == 'S') {
        forbidden[i][col] = true;
      }      
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      char c;
      cin >> c;
      grid[i][j] = c;
      if (c == 'S') start = {i, j};
      else if (c == 'C') {
        cameras.push_back({i, j});
      }
    }
  }
  check_cameras();
  bfs(start);
  for (int i=0; i<N; i++){
    for (int j=0; j<M; j++){
      if (grid[i][j] == '.'){
        cout << steps[i][j] << endl;
      }
    }
  }
}