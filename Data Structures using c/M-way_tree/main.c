#include <stdio.h>
#include <stdlib.h>
#define MIN 2
int max=0;
  struct btreeNode {
        int val[max + 1], count;
        struct btreeNode *link[max + 1];
  };

  struct btreeNode *root;
  struct btreeNode * createNode(int val, struct btreeNode *child) {
        struct btreeNode *newNode;
        newNode = (struct btreeNode *)malloc(sizeof(struct btreeNode));
        newNode->val[1] = val;
        newNode->count = 1;
        newNode->link[0] = root;
        newNode->link[1] = child;
        return newNode;
  }

  void addValToNode(int val, int pos, struct btreeNode *node,
                        struct btreeNode *child) {
        int j = node->count;
        while (j > pos) {
                node->val[j + 1] = node->val[j];
                node->link[j + 1] = node->link[j];
                j--;
        }
        node->val[j + 1] = val;
        node->link[j + 1] = child;
        node->count++;
  }

  void splitNode (int val, int *pval, int pos, struct btreeNode *node,
     struct btreeNode *child, struct btreeNode **newNode) {
        int median, j;

        if (pos > MIN)
                median = MIN + 1;
        else
                median = MIN;

        *newNode = (struct btreeNode *)malloc(sizeof(struct btreeNode));
        j = median + 1;
        while (j <= max) {
                (*newNode)->val[j - median] = node->val[j];
                (*newNode)->link[j - median] = node->link[j];
                j++;
        }
        node->count = median;
        (*newNode)->count = max - median;

        if (pos <= MIN) {
                addValToNode(val, pos, node, child);
        } else {
                addValToNode(val, pos - median, *newNode, child);
        }
        *pval = node->val[node->count];
        (*newNode)->link[0] = node->link[node->count];
        node->count--;
  }
  int setValueInNode(int val, int *pval, struct btreeNode *node, struct btreeNode **child) {

        int pos;
        if (!node) {
                *pval = val;
                *child = NULL;
                return 1;
        }

        if (val < node->val[1]) {
                pos = 0;
        } else {
                for (pos = node->count;
                        (val < node->val[pos] && pos > 1); pos--);
                if (val == node->val[pos]) {
                        printf("Duplicates not allowed\n");
                        return 0;
                }
        }
        if (setValueInNode(val, pval, node->link[pos], child)) {
                if (node->count < max) {
                        addValToNode(*pval, pos, node, *child);
                } else {
                        splitNode(*pval, pval, pos, node, *child, child);
                        return 1;
                }
        }
        return 0;
  }

  void insertion(int val) {
        int flag, i;
        struct btreeNode *child;

        flag = setValueInNode(val, &i, root, &child);
        if (flag)
                root = createNode(i, child);
  }

  void copySuccessor(struct btreeNode *myNode, int pos) {
        struct btreeNode *dummy;
        dummy = myNode->link[pos];

        for (;dummy->link[0] != NULL;)
                dummy = dummy->link[0];
        myNode->val[pos] = dummy->val[1];

  }
  void removeVal(struct btreeNode *myNode, int pos) {
        int i = pos + 1;
        while (i <= myNode->count) {
                myNode->val[i - 1] = myNode->val[i];
                myNode->link[i - 1] = myNode->link[i];
                i++;
        }
        myNode->count--;
  }

  void doRightShift(struct btreeNode *myNode, int pos) {
        struct btreeNode *x = myNode->link[pos];
        int j = x->count;

        while (j > 0) {
                x->val[j + 1] = x->val[j];
                x->link[j + 1] = x->link[j];
        }
        x->val[1] = myNode->val[pos];
        x->link[1] = x->link[0];
        x->count++;

        x = myNode->link[pos - 1];
        myNode->val[pos] = x->val[x->count];
        myNode->link[pos] = x->link[x->count];
        x->count--;
        return;
  }

  void doLeftShift(struct btreeNode *myNode, int pos) {
        int j = 1;
        struct btreeNode *x = myNode->link[pos - 1];

        x->count++;
        x->val[x->count] = myNode->val[pos];
        x->link[x->count] = myNode->link[pos]->link[0];

        x = myNode->link[pos];
        myNode->val[pos] = x->val[1];
        x->link[0] = x->link[1];
        x->count--;

        while (j <= x->count) {
                x->val[j] = x->val[j + 1];
                x->link[j] = x->link[j + 1];
                j++;
        }
        return;
  }
  void mergeNodes(struct btreeNode *myNode, int pos) {
        int j = 1;
        struct btreeNode *x1 = myNode->link[pos], *x2 = myNode->link[pos - 1];

        x2->count++;
        x2->val[x2->count] = myNode->val[pos];
        x2->link[x2->count] = myNode->link[0];

        while (j <= x1->count) {
                x2->count++;
                x2->val[x2->count] = x1->val[j];
                x2->link[x2->count] = x1->link[j];
                j++;
        }

        j = pos;
        while (j < myNode->count) {
                myNode->val[j] = myNode->val[j + 1];
                myNode->link[j] = myNode->link[j + 1];
                j++;
        }
        myNode->count--;
        free(x1);
  }
  void adjustNode(struct btreeNode *myNode, int pos) {
        if (!pos) {
                if (myNode->link[1]->count > MIN) {
                        doLeftShift(myNode, 1);
                } else {
                        mergeNodes(myNode, 1);
                }
        } else {
                if (myNode->count != pos) {
                        if(myNode->link[pos - 1]->count > MIN) {
                                doRightShift(myNode, pos);
                        } else {
                                if (myNode->link[pos + 1]->count > MIN) {
                                        doLeftShift(myNode, pos + 1);
                                } else {
                                        mergeNodes(myNode, pos);
                                }
                        }
                } else {
                        if (myNode->link[pos - 1]->count > MIN)
                                doRightShift(myNode, pos);
                        else
                                mergeNodes(myNode, pos);
                }
        }
  }
  void traversal(struct btreeNode *myNode) {
        int i;
        if (myNode) {
                for (i = 0; i < myNode->count; i++) {
                        traversal(myNode->link[i]);
                        printf("%d ", myNode->val[i + 1]);
                }
                traversal(myNode->link[i]);
        }
  }

  int main() {
        int val, ch;
        printf("Enter Value of M in m-way Tree\n");
        scanf("%d",&max);
        while (1) {
                printf("1. Insertion\t 2.Traversal\n");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter your input:");
                                scanf("%d", &val);
                                insertion(val);
                                break;
                        case 2:
                                traversal(root);
                                break;
                        case 3:
                                exit(0);
                        default:
                                printf("U have entered wrong option!!\n");
                                break;
                }
                printf("\n");
        }
  }
