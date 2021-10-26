#include <stdio.h>
#include <stdlib.h>
typedef struct FHNode
    {
        int key;
        int mark;
        int degree;
        struct FHNode *next, *prev, *parent, *child;
        } FHNode;
    FHNode *t, *x;
typedef struct FibHeap
    {
        struct FHNode *roots;
        struct FHNode *minptr;
        int n;
    } FibHeap;
FibHeap *H, *H1, *H2;
FHNode *newNode(FHNode *t)
    {
        t = (FHNode *)malloc(sizeof(FHNode));
        t->key = 0;
        t->degree = 0;
        t->mark = 0;
        t->prev = t->next = t;
        t->child = t->parent = NULL;
        return t;
    }
FibHeap *newHeap()
    {
        H = malloc(sizeof(FibHeap));
        H->roots = NULL;
        H->minptr = NULL;
        H->n = 0;
        return H;
    }
void swap(FHNode **x, FHNode **y)
    {
        struct FHNode *p = *x;
        *x = *y;
        *y = p;
    }
FibHeap *insert(FibHeap *H, int val)
    {
        FHNode *temp = (FHNode *)malloc(sizeof(FHNode));
        temp->key = val;
        temp->parent = temp->child = NULL;
        temp->prev = temp->next = temp;
        temp->degree = 0;
        temp->mark = 0;
        if (!H)
          H = newHeap();
        if (!H->roots)
          H->roots = temp;
        FHNode *last = H->roots->prev;
        last->next = temp;
        temp->prev = last;
        temp->next = H->roots;
        H->roots->prev = temp;
        if (H->minptr == NULL || temp->key < H->minptr->key)
           H->minptr = temp;
        H->n++;
        printf("Node Inserted\n");
        return H;
    }
void min()
    {
        printf("Minimum Key Is : %d\n", H->minptr->key);
    }
FHNode *addNode(FHNode *old, FHNode *new)
    {
        if (!old)
           return new;
        FHNode *oldPrev = old->prev;
        oldPrev->next = new;
        new->prev = oldPrev;
        new->next = old;
        old->prev = new;
        return old;
    }
FHNode *removeNode(FHNode *old, FHNode *toremove)
    {
        FHNode *l, *r;
        if (toremove->next == toremove && old == toremove)
          {
             old = NULL;
           }
        else
          {
             l = toremove->prev;
             r = toremove->next;
             l->next = r;
             r->prev = l;
             toremove->next = toremove;
             toremove->prev = toremove;
             if (toremove == old)
                 old = r;
          }
        return old;
    }
int maxdeg(int n)
    {
        int d, S, S2 = 0, S1 = 1;
        for (S = S1 + S2, d = 2; S < n; ++d)
            {
              S2 = S1;
              S1 = S;
                S = S1 + S2;
             }
        return d - 2;
    }
FHNode *link(FHNode *x, FHNode *y)
    {
        if (y->key < x->key)
           swap(&x, &y);
        x->child = addNode(x->child, y);
        y->parent = x;
        x->degree++;
        y->mark = 0;
        return x;
    }
void consolidate(FibHeap *H)
    {
        if (!H->roots)
          {
             printf("EMPTY HEAP\n");
             return;
            }
        int D = maxdeg(H->n) + 1;
        FHNode *x, *y;
        FHNode *A[D + 1];
        int i, d;
        for (i = 0; i <= D; ++i)
              A[i] = NULL;
        while (H->roots)
            {
               x = H->roots;
               d = x->degree;
               H->roots = removeNode(H->roots, x);
               while (A[d])
                    {
                       y = A[d];
                       x = link(x, y);
                       A[d++] = NULL;
                      };
               A[d] = x;
            };
        H->minptr = H->roots = NULL;
        for (i = 0; i <= D; ++i)
            if (A[i])
              {
                 H->roots = addNode(H->roots, A[i]);
                 if (H->minptr == NULL || A[i]->key < H->minptr->key)
                    H->minptr = A[i];
               }
            free(A);
    }
void extractMin(FibHeap *H)
    {
        FHNode *z, *zChild, *temp;
        z = H->minptr;
        if (z)
          {
             zChild = z->child;
             if (zChild)
              {
                do
                   {
                      temp = zChild;
                      zChild = zChild->next;
                      addNode(H->roots, temp);
                      temp->parent = NULL;
                     } while (zChild != z->child);
                }
        H->roots = removeNode(H->roots, z);
        H->n--;
        if (H->n == 0)
          {
             printf("HEAP IS EMPTY\n");
          }
        else
          {
             consolidate(H);
             free(z);
           }
        }
    }
void cut(FibHeap *H, FHNode *x)
    {
        FHNode *y;
        y = x->parent;
        y->child = removeNode(y->child, x);
        y->degree--;
        H->roots = addNode(H->roots, x);
        x->parent = NULL;
        x->mark = 0;
    }
void cascadeCut(FibHeap *H, FHNode *z)
    {
       FHNode *p = (FHNode *)malloc(sizeof(FHNode));
       p = z->parent;
       if (p)
         {
           if (!z->mark)
               z->mark = 1;
          else
            {
               cut(H, z);
               cascadeCut(H, p);
            }
        }
    }
FHNode *search(FHNode *x, int key)
    {
       FHNode *y = (FHNode *)malloc(sizeof(FHNode));
       FHNode *w = (FHNode *)malloc(sizeof(FHNode));
       w = x;
       y = NULL;
       if (x)
         {
            do
               {
                  if (w->key == key)
               {
                  y = w;
                  break;
                }
       else
            y = search(w->child, key);
       if (y)
         break;
       w = w->next;
               } while (w != x);
         }
        return y;
    }
void decKey(FibHeap *H, FHNode *x, int val)
    {
        if (val > x->key)
          {
            printf("Entered key is more than existing\n");
            return;
           }
        printf("%d is Decreased to %d\n", x->key, val);
        x->key = val;
        FHNode *y = x->parent;
        if (y)
        if (y != NULL && (x->key < y->key))
          {
            cut(H, x);
            cascadeCut(H, y);
           }
        if (x->key < H->minptr->key)
          H->minptr = x;
        }
void delete (FibHeap *H, FHNode *x)
     {
         double infnty = -1e99;
         decKey(H, x, infnty);
         extractMin(H);
    }
FHNode *concatenate(FHNode *old1, FHNode *old2)
    {
        struct FHNode *new1 = old1->prev;
        struct FHNode *new2 = old2->prev;
        new1->next = old2;
        old2->prev = new1;
        new2->next = old1;
        old1->prev = new2;
        return old1;
    }
FibHeap *merge(FibHeap *H1, FibHeap *H2)
    {
        if ((!H1) || (!H1->roots))
           return H2;
        if ((!H2) || (!H2->roots))
           return H1;
        H = newHeap();
        H->roots = concatenate(H1->roots, H2->roots);
        if (H1->minptr->key < H2->minptr->key)
           H->minptr = H1->minptr;
       else
           H->minptr = H2->minptr;
        H->n = H1->n + H2->n;
        free(H1);
        free(H2);
        return H;
    }
void display(FHNode *t)
    {
        FHNode *q;
        q = t;
        do
          {
             printf("%d ", q->key);
             if (q->child != NULL)
               {
                  display(q->child);
               }
        q = q->next;
         }
         while (q != t);
    }
int main()
    {
        x = newNode(x);
        int ch, val, c;
        H1 = H2 = NULL;
        do
          {
             printf("1. Operations on HEAP 1 \n2. Operations on HEAP 2\n3. UNION\n4. EXIT \n");
             scanf("%d", &c);
             switch (c)
                {
                   case 1: if (!H1)
                               H1 = newHeap();
                                 H = H1;
                                printf("\tHEAP 1\n");
                                break;
                   case 2: if (!H2)
                                H2 = newHeap();
                                  H = H2;
                                 printf("\tHEAP 2\n");
                                 break;
                   case 3: H = merge(H1, H2);
                               printf("Union of Heaps H1 and H2 Successfull\n");
                               break;
                   case 4: exit(0);
                }
        printf("Select Operation : \n");
        printf("1:Initialize A New HEAP\n");
        printf("2:Insert\n");
        printf("3:Display Minimum\n");
        printf("4:Extract Minimum\n");
        printf("5:Search Specific Node\n");
        printf("6:Decrease Key\n");
        printf("7:Delete Specific Node\n");
        printf("8:Display\n");
        printf("9:EXIT\n");
        do
          {
            scanf("%d", &ch);
            switch (ch)
             {
                 case 1: newHeap();
                              printf("New Heap Created\n");
                              break;
                 case 2: printf("Enter the Key: \n");
                             scanf("%d", &val);
                             H = insert(H, val);
                             break;
                 case 3: if (H->roots != NULL)
                               min();
                             else
                                {
                                   printf("HEAP IS EMPTY\n");
                                   break;
                                }
                              break;
                 case 4: if (H->minptr)
                               {
                                 c = H->minptr->key;
                                 extractMin(H);
                                 if (H->roots)
                                   {
                                      t = H->roots;
                                     display(t);
                                     printf("\nExtracted Node Is : %d\n", c);
                                    }
                               }
                           else
                                 {
                                     printf("EMPTY HEAP\n");
                                     break;
                                  }
                           break;
                      case 5: printf("Select The Node : \n");
                                  scanf("%d", &val);
                                  x = search(H->minptr, val);
                                   if (!x)
                                     printf("THE NODE IS NOT IN HEAP\n");
                                   else
                                     printf("THE NODE IS IN THE HEAP\n");
                                   break;
                       case 6: printf("Nodes Present in the heap are : \n");
                                   t = H->roots;
                                   display(t);
                                    printf("\n");
                                    printf("Select the Node: ");
                                    scanf("%d", &val);
                                    x = search(H->minptr, val);
                                    if (!x)
                                      printf("\nTHE NODE IS NOT IN HEAP\n");
                                    else
                                       {
                                           printf("Enter the New key Value :\n");
                                           scanf("%d", &val);
                                           decKey(H, x, val);
                                            printf("Now The Heap is:\n");
                                            display(t);
                                            printf("\n");
                                        }
                                  break;
                         case 7: printf("SELECT THE NODE :\n");
                                     scanf("%d", &val);
                                     x = search(H->minptr, val);
                                     if (!x)
                                         printf("THE NODE IS NOT IN HEAP\n");
                                     else
                                        {
                                           printf("The Selected NOde is: %d\n", x->key);
                                           delete (H, x);
                                           printf("NODE DELETED\n");
                                         }
                                       break;
                          case 8: t = H->roots;
                                       if (t == NULL)
                                         {
                                            printf("HEAP IS EMPTY\n");
                                            break;
                                            }
                                       else
                                          {
                                             printf("The Nodes in the Heap Are:\n");
                                             display(t);
                                           }
                                       printf("\n");
                                           break;
                        case 9: break;
                    }
               } while (ch != 9);
         if (c != 1)
           H2 = H;
        else
           H1 = H;
        } while (c != 4);
        return 0;
    }
