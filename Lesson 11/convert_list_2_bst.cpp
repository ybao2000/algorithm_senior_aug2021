#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int d){
    data = d;
    left = NULL;
    right = NULL;
  }
};

// recursive call
Node* form_tree(int *arr, int start, int end){
  int len = end - start + 1;
  if (len == 1){
    return new Node(arr[start]);
  }
  else if(len == 2){
    Node* root = new Node(arr[end]);
    Node* left = new Node(arr[start]);
    root->left = left;
    return root;
  }
  else{
    int mid = (start + end )/2;
    Node* root = new Node(arr[mid]);
    root->left = form_tree(arr, start, mid-1);
    root->right = form_tree(arr, mid+1, end);
    return root;
  }
}

// print out the node according to pre-order
// recursive call
// root, left, right
void pre_order(Node *root){
  cout << root->data << endl;
  if (root->left != NULL){
    // you have a left
    pre_order(root->left);
  }
  if(root->right != NULL){
    pre_order(root->right);
  }
}

// left, root, right
void in_order(Node *root){
  if (root->left != NULL){
    // you have a left
    in_order(root->left);
  }
  cout << root->data << endl;
  if(root->right != NULL){
    in_order(root->right);
  }
}

// left, right, root
void post_order(Node *root){
  if (root->left != NULL){
    // you have a left
    post_order(root->left);
  }
  if(root->right != NULL){
    post_order(root->right);
  }
    cout << root->data << endl;
}

//  bfs: levels
void bfs(Node *root){
  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    Node* cur_node = q.front();
    q.pop();
    cout << cur_node->data << endl;
    if(cur_node->left != NULL){
      // you have a left
      q.push(cur_node->left);
    }
    if(cur_node->right != NULL){
      // you have a right
      q.push(cur_node->right);
    }
  }
}

// bst is for search 
Node* search(Node* root, int a){
  if(root == NULL) return NULL;
  if(root->data == a) return root;
  else if (root->data > a) return search(root->left, a);
  else return search(root->right, a);
}

int main(){
  int arr[10] = {31, 82, 52, 11, 16, 10, 32, 17, 44, 39};
  // sort it first
  sort(arr, arr + 10);
  Node* root = form_tree(arr, 0, 9);
  // bfs(root);
  // in_order(root);
  Node* node = search(root, 12);
  if (node != NULL) cout << "find it" << endl;
  else cout << "Not found" << endl;
}