#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    struct Node* left;
    struct Node* right;
    int data;
}Node;
Node* newNode(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->left=node->right=NULL;
    node->data=data;
    return node;
}

  int getHeight(Node* root){
    int height =0;
    if (root) {
        if (root->left || root->right) {
             int leftheight = 0, rightheight = 0;
            if (root->left) {
                leftheight = getHeight(root->left);
            }
            if (root->right) {
                rightheight = getHeight(root->right);
            }
            if (leftheight > rightheight) {
                height = leftheight + 1;
            } 
            else {
                height = rightheight + 1;
            }
        }
         else{ 
             height = height + 1;
        }
    }
    return height;
}


Node* insert(Node* root,int data){
    if(root==NULL)
        return newNode(data);
    else{
        Node* cur;
        if(data<=root->data){
            cur=insert(root->left,data);
            root->left=cur;                
        }
        else{
            cur=insert(root->right,data);
            root->right=cur;
        }
        
    }
    return root;
}
int main(){
    Node* root=NULL;
    int T,data;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&data);
        root=insert(root,data);
    }
    int height=getHeight(root);
    printf("%d",height);
    return 0;
    
}
