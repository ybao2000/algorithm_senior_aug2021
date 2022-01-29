#include <bits/stdc++.h>
using namespace std;

const int MIN = -2e9;
const int ARR_SIZE = 100;
const int TREE_SIZE = 1000;
int N;
int arr[ARR_SIZE];
int tree[TREE_SIZE];

// this is recursive
// you need to base case
void build_tree(int node, int start, int end)
{
  if (start == end) {
    tree[node] = arr[start];
  } else {
    int mid = (start + end) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;
    build_tree(left_node, start,  mid);
    build_tree(right_node, mid+1, end);
    tree[node] = max(tree[left_node], tree[right_node]);
  }
}

void print_tree() {
  int height = log2(N) + 1;
  int tree_size = pow(2, height+1) - 1;
  for(int i=0; i<tree_size; i++){
    // cout is not good for format output
    printf("Tree[%d] = %d\n", i, tree[i]);
  }
}

void update_tree(int node, int start, int end, int idx, int val){
  if(start == end) {
    arr[idx] = val;
    tree[node] = val;
  } else {
    int mid = (start + end) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;  
    if (idx <= mid) { // left side
      update_tree(left_node, start, mid, idx, val);
    } else {
      update_tree(right_node, mid+1, end, idx, val);
    }
    tree[node] = max(tree[left_node], tree[right_node]);
  }
}

int query_tree(int node, int start, int end, int L, int R){
  printf("start = %d\n", start);
  printf("end   = %d\n", end);
  printf("\n");

  if(L > end || R < start) {
    return MIN;
  } else if (start >= L && end <= R) { // your segment is in the range
    return tree[node];
  } else {
    int mid = (start + end) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2; 
    int q1 = query_tree(left_node, start, mid, L, R);
    int q2 = query_tree(right_node, mid+1, end, L, R);
    return max(q1, q2); 
  }
}

int main() {
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> arr[i];
  }
  fill(tree, tree+TREE_SIZE, MIN);
  build_tree(0, 0, N-1);
  // print_tree();
  // int x, y, z;
  // cin >> x >> y >> z;
  // update_tree(0, 0, N-1, y, z);
  // print_tree();
  int q;
  cin >> q;
  for(int i=0; i<q; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x == 1) {
      // query
      cout << query_tree(0, 0, N-1, y, z) << "\n";
    }
    else {
      update_tree(0, 0, N-1, y, z);
    }
  }
}