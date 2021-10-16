#include <iostream>
#include <queue>
using namespace std;

struct Node {
  string data;
  Node* left;
  Node* right;
  Node(string d){
    data = d;
    left = NULL;
    right = NULL;
  }
};

Node* init_tree() {
  Node *a = new Node("a");
  Node *b = new Node("b");
  Node *c = new Node("c");
  Node *d = new Node("d");
  Node *e = new Node("e");
  Node *f = new Node("f");
  Node *g = new Node("g");
  Node *h = new Node("h"); 
  Node *i = new Node("i");  
  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  e->left = g;
  e->right = h;
  c->right = f;
  f->right = i;
  return a;
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

int main() {
  Node *root = init_tree();
  // pre_order(root);
  // in_order(root);
  // post_order(root);
  bfs(root);
}