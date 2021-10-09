#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
  int N;
  cin >> N;
  char c1, c2;
  map<char, vector<char>> tree;
  for(int i=0; i<N; i++){
    cin >> c1 >> c2;
    tree[c2].push_back(c1);
  }
  for(auto node: tree){
    cout << node.first << ": "; // parent
    for(auto child : node.second) {
      cout << child << " ";
    }
    cout << endl;
  }
}