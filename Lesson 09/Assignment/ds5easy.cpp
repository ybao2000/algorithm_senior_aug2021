#include <iostream>
#include <vector>         // slower than array
#include <unordered_map>  // hashtable inside O(1)
#include <unordered_set>  // hashtable, O(1)
#include <queue>
#include <climits>      // it has MAX_INT, MIN_INT
using namespace std;

int N, M; // make it global, so they can be shared by different functions
vector<int> weights;
unordered_map<int, vector<int>> edges;
unordered_map<int, unordered_set<int>> children;  // to store children information
unordered_map<int, int> parents;  // to store parent information
int root;
vector<int> path;

inline int min(int x, int y) {return x < y ? x : y;}  // inline means 
inline int max(int x, int y) {return x > y ? x : y;}

// use bfs to construct the tree
void build_tree(int node){
  root = node;
  queue<int> q;
  vector<bool> visited(N, false); // all nodes are not visited
  q.push(root);
  visited[root] = true;
  parents[root] = -1;
  while(!q.empty()){
    int cur_node = q.front(); 
    q.pop();
    for(int sub_node : edges[cur_node]){
      if(!visited[sub_node]){ // if already visitied, that is parent
        q.push(sub_node);
        children[cur_node].insert(sub_node);
        parents[sub_node] = cur_node;
        visited[sub_node] = true;
      }
    }
  }
}

// you have to do it in O(logn)
void change_root(int node){
  root = node;
  int new_parent = -1;
  while (node != -1){
    int orig_parent = parents[node];
    // for each node, we modified both children and parent
    parents[node] = new_parent;
    if (new_parent != -1){
      children[node].erase(new_parent);
    }
    children[node].insert(orig_parent);
    // this is to update the node and new_parent
    new_parent = node;
    node = orig_parent;
  }
}

// O(logn)
int get_level(int x){
  int level = 0;
  int node =x ;
  while(node != root){
    level++;
    node = parents[node];
  }
  return level;
}

// O(LogN)
void get_path(int x, int y){
  path.clear();
  int node_1 = x;
  int node_2 = y;
  int level_1 = get_level(node_1);
  int level_2 = get_level(node_2);
  while (level_1 > level_2){
    path.push_back(node_1);
    node_1 = parents[node_1];
    level_1--;
  }
  while(level_1 < level_2){
    path.push_back(node_2);
    node_2 = parents[node_2];
    level_2--;
  }
  while(node_1 != node_2){
    path.push_back(node_1);
    path.push_back(node_2);
    node_1 = parents[node_1];
    node_2 = parents[node_2];
  }
  path.push_back(node_1);
}

void mod_path(int x, int y, int z, int K){
  get_path(x, y);
  for (int node : path){
    if (K== 1){
      weights[node] = z;
    }
    else {
      weights[node] += z;
    }
  }
}

void get_value(int x, int y, int K){
  get_path(x, y);
  if (K == 3){
    int v_min = INT_MAX;
    for(int node : path){
      v_min = min(v_min, weights[node]);
    }
    cout << v_min << endl;
  }
  else if (K==4){
    int v_max = INT_MIN;
    for(int node : path){
      v_max = max(v_max, weights[node]);
    }
    cout << v_max << endl;
  }
  else {
    int v_sum = 0;
    for(int node : path){
      v_sum += weights[node];
    }
    cout << v_sum << endl;
  }
}

// O(logn)
void change_parent(int x, int y){
  // first, make sure y is not sub node of x
  int node = y;
  int level_1 = get_level(x);
  int level_2 = get_level(y);
  while(level_2 > level_1) {
    node = parents[node];
    level_2--;
  }
  if (node == x) return;  // y is a sub node of x

  // change children/parents for x and y
  int x_parent = parents[x];  // this is the original parent of x
  children[x_parent].erase(x);
  children[y].insert(x);
  parents[x] = y;
}

void get_LCM(int x, int y){
  int node_1 = x;
  int node_2 = y;
  int level_1 = get_level(node_1);
  int level_2 = get_level(node_2);
  while (level_1 > level_2){
    node_1 = parents[node_1];
    level_1--;
  }
  while(level_1 < level_2){
    node_2 = parents[node_2];
    level_2--;
  }
  while(node_1 != node_2){
    node_1 = parents[node_1];
    node_2 = parents[node_2];
  }
  cout << node_1+1 << endl;
}

int main(){
  cin >> N >> M; 
  for(int i=0; i<N; i++){
    int weight;
    cin >> weight;
    weights.push_back(weight);
  }
  for(int i=0; i<N-1; i++){
    int a, b;
    cin >> a >> b;
    edges[a-1].push_back(b-1);
    edges[b-1].push_back(a-1);
  }
  int node;
  cin >> node;
  build_tree(node-1);
  
  for(int i=0; i<M; i++){
    int K;
    int x, y, z;
    cin >> K;
    switch(K){
      case 0: // change root
        cin >> x;
        change_root(x-1);
        break;
      case 1: // path modification
      case 2: // path increment
        cin >> x >> y >> z;
        mod_path(x-1, y-1, z, K);
        break;
      case 3: // get min
      case 4: // get max
      case 5: // get sum
        cin >> x >> y;
        get_value(x-1, y-1, K);
        break;
      case 6: // change parent
        cin >> x >> y;
        change_parent(x-1, y-1);
        break;
      case 7: // get LCM
        cin >> x >> y;
        get_LCM(x-1, y-1);
        break;
    }
  }
}