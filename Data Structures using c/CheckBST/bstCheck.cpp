#include <iostream>
#include <climits>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
}

struct Node * createNode(int d) {
   struct Node * root = new Node;
   root -> data = d;
   root -> left = NULL;
   root -> right = NULL;
   return root;
}

bool checkBST(Node* root, int minVal, int maxVal){
    if(!root) return true;
    if(root->data>=maxVal || root->data<=minVal)
        return false;
    return checkBST(root->left, minVal, root->data) &&
        checkBST(root->right, root->data, maxVal);
}

bool checkBST(Node* root) {
  return checkBST(root, INT_MIN, INT_MAX);
}

int main() {
   struct Node * root = NULL;
   root = createNode(1);
   root -> left = createNode(2);
   root -> right = createNode(3);
   root -> left -> right = createNode(4);
   root -> left -> left = createNode(5);
   root -> right -> left = createNode(6);
   if (checkBST(root)) {
      cout << "1" << endl;
   } else {
      cout << "0" << endl;
   }
   return 0;
}
