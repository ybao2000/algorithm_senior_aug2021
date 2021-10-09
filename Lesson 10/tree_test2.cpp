#include <iostream>
#include <vector>
using namespace std;

// recursive: 
// 1. recursive function
// 2. recursive structure
struct Node {
  string data; // this is to store the info of the node
  vector<Node*> children;
  Node(string d){  // constructor: a special function, whenever you create a object, 
    data = d;
  }
  void add_child(Node* child){
    children.push_back(child);
  }
  Node* add_child_value(string s){
    Node *child = new Node(s);
    children.push_back(child);
    return child;
  }
};

void do_something(Node *root){
  for(auto node : root->children){
    cout << node->data << endl;
  }
}

Node* init_tree(){
  // everything inside the function is local
  // local varaible will be destroyed when the function is returned.
  Node *root = new Node("a");
  Node *node_b = new Node("b");
  root->children.push_back(node_b); // very awkward
  Node *node_c = new Node("c");
  root->children.push_back(node_c);
  // Node node_d = Node("d");
  // root.add_child(node_d);  // this is a better way
  root->add_child_value("d");
  Node *node_e = new Node("e");
  node_b->add_child(node_e);
  return root;
}

int main(){
  Node* root = init_tree();
  do_something(root);
}