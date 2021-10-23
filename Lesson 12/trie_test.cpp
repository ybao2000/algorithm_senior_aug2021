#include <iostream>
using namespace std;

// example of characters
const int SIZE = 26;  // here wu just assume lower case letters

struct TrieNode {
  TrieNode* children[SIZE]; // 0: a, 1: b, ..., 25: z, array of pointers
  bool endOfWord; // endOfWord means this is an end of a word, it still could have children
};

TrieNode* create_node(){
  TrieNode* new_node = new TrieNode();  // create an empty node
  new_node->endOfWord = false; // default, it is not end of word
  for (int i=0; i<SIZE; i++) {
    // go through the array
    new_node->children[i] = NULL; // it doesn't have anything yet
  }
  return new_node; 
}

void insert(TrieNode *root, string word){
  TrieNode* cur_node = root;
  for(int i=0; i<word.length(); i++){
    int index = word[i] - 'a';
    if (!cur_node->children[index]){  // this letter doesn't exist
      cur_node->children[index] = create_node();
    }
    cur_node = cur_node->children[index];
  }
  // don't forget to mark the endOfWord
  cur_node->endOfWord = true;
}

bool search(TrieNode *root, string word){
  TrieNode* cur_node = root;
  for(int i=0; i<word.length(); i++){
    int index = word[i] - 'a';
    if(!cur_node->children[index]) return false;
    cur_node = cur_node->children[index];
  }
  return cur_node->endOfWord;
}

int main(){
  string words[] = {"cabbage", "celery", "carrot", "cucumber", "pepper", "pea", "potato", "tomato", "tofu"};
  TrieNode* root = create_node();
  int size = sizeof(words) / sizeof(words[0]);  // 9
  for(int i=0; i<size; i++){
    insert(root, words[i]);
  }
  cout << (search(root, "pepper") ? "Yes" : "No") << endl;
  cout << (search(root, "pot") ? "Yes" : "No") << endl;
}