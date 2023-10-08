#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct Node * createNode(int d) {
   struct Node * root = new Node;
   root -> data = d;
   root -> left = NULL;
   root -> right = NULL;
   return root;
}

Node * findNode(Node *r, int v){
    if(!r) return NULL;
    while(r && r->data!=v){
        r = r->data>v ?r->left : r->right;
    }
    return r;
}

Node *lcaSearch(Node *root, int v1,int v2) {
    Node *p=findNode(root,v1);
    Node *q=findNode(root,v2);
    return lca(root,p,q); 
}

Node *lca(Node *root, Node *p, Node *q){
    if(!root) return NULL;
    if(root->data>p->data && root->data>q->data)
        return lca(root->left,p,q);
    if(root->data<p->data && root->data<q->data)
        return lca(root->right,p,q);
    return root;
}

int main() {
   struct Node * root = NULL;
   struct Node * result = NULL;
   int v1, v2;
   scanf("%d%d", &v1, &v2);
   root = createNode(1);
   root -> left = createNode(2);
   root -> right = createNode(3);
   root -> left -> right = createNode(4);
   root -> left -> left = createNode(5);
   root -> right -> left = createNode(6);

   result->data = lcaSearch(root, v1, v2);
   if (result) {
    printf("%d\n", result->data);
   }
   return 0;
}

