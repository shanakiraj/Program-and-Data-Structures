#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}
int count = 0;
// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  if(!find(x)){

  if(root==NULL){
   root = new AVLNode;
   root->value = x;
   count++;
   insert(root, x);
  }
  else{
    count++;
    insert(root, x);
}
  //printTree();
  }
  
}

void AVLTree::insert(AVLNode*& node, string x){
  
  if(node == NULL){
    node = new AVLNode;
    node -> value = x;
    }
  
  if(x < node->value){
      insert(node->left, x); 	  
  }

  if(x > node->value){
      insert(node->right, x);
  }
  
  node->height = 1 + max(height(node->left), height(node->right));
  balance(node);
}


// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string value = "";
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  value = "";
  return pathTo(root, x);
}

string AVLTree::pathTo(AVLNode* node, string x) const{
  
  if(!(find(x))){
    value = " ";
    return value;
  }

  if(x<node->value){
    value.insert(value.length(), node->value);
    value.insert(value.length(), " ");
    return pathTo(node->left, x);
  }
  
  if(x>node->value){
    value.insert(value.length(), node->value);
    value.insert(value.length(), " ");
    return pathTo(node->right, x);
  }
  else{
    value.insert(value.length(), node-> value);
    return value;
  }
  
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  if(find(root, x) == NULL){
    return false;
  }
  else{
    return true;
  }
  
}

AVLNode* AVLTree::find(AVLNode* node, string x) const{
   if(node == NULL){
    return NULL;
  }
  
  else if(x<node->value){
    return find(node->left, x);
  }
  
  else if(x>node->value){
    return find(node->right, x);
  }
  else{
    return node;
  }
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  return count;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.

void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  
  if(height(n->right) - height(n->left)  == 2){
    if(height(n->right->right) - height(n->right->left) < 0 ){
     rotateRight(n->right);
     }
    rotateLeft(n);
  }
  else if(height(n->right) - height(n->left)  == -2){
     if(height(n->right) > height(n->left)){
    rotateLeft(n->left);
     }
    rotateRight(n);
  }
   n->height = 1 + max(height(n->left), height(n->right));
  
}
    

// rotateLeft performs a single rotation on node n with its right child.
void AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  
  AVLNode *node1 = n->right;
  AVLNode *node2 = node1->left;
  
  node1->left = n;
  n->right = node2;
  
  n->height = 1 + max(height(n->left), height(n->right));
  node1->height = 1 + max(height(node1->left), height(node1->right));

  n = node1;
}

// rotateRight performs a single rotation on node n with its left child.
void AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE

  AVLNode *node1 = n-> left;
  AVLNode *node2 = node1->right;

  node1->right = n;
  n->left = node2;
  n->height = 1 + max(height(n->left), height(n->right));
  node1->height = 1 + max(height(node1->left), height(node1->right));
  
  n = node1;
  
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
	    count--;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    //count--;

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
    
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}


void AVLTree::balanceHeight(AVLNode* node){
  node->height = 1 + max(height(node->left), height(node->right));
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
