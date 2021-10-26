#include <stdio.h>
#include <stdlib.h>
struct BhNode
    {
        int key, degree;
        struct BhNode *par, *child, *sib;
    };
struct list
    {
        struct BhNode *node;
        struct list *next;
        struct list *prev;
    };
struct BhNode *newNode(int k)
    {
        struct BhNode *node;
        node = (struct BhNode *)malloc(sizeof(struct BhNode));
        node->key = k;
        node->degree = 0;
        node->par = node->child = node->sib = NULL;
        return node;
    }
struct list *CreateHeap(struct list *heap)
    {
       struct list *templ1 = heap;
       struct list *templ2 = heap->next;
       while (templ2)
          {
             if (templ1->node->degree == templ2->node->degree)
              {
                 if (templ1->node->key > templ2->node->key)
                   {
                      templ1->node->sib = templ2->node->child;
                      templ2->node->child = templ1->node;
                      templ1->node->par = templ2->node;
                      templ2->node->degree++;
                   }
        else
          {
              templ2->node->sib = templ1->node->child;
              templ1->node->child = templ2->node;
              templ2->node->par = templ1->node;
              templ1->node->degree++;
              templ2->node = templ1->node;
         }
       }
      else
             break;
       heap = templ2;
       templ1 = templ1->next;
       templ2 = templ2->next;
        }
       heap->prev = NULL;
       return heap;
    }
struct list *insert(struct list *heap, int k)
    {
        struct BhNode *node = newNode(k);
        struct list *l;
        l = (struct list *)malloc(sizeof(struct list));
        l->node = node;
        l->next = NULL;
        l->prev = NULL;
       if (heap == NULL)
          {
             return l;
          }
        l->next = heap;
        heap->prev = l;
        heap = l;
        return CreateHeap(heap);
    }
struct list *merge(struct list *templ1, struct list *templ2)
    {
       struct list *newl;
       newl = NULL;
       struct list *par = templ1;
       struct list *q = templ2;
       while (par && q)
          {
             struct list *l;
             l = (struct list *)malloc(sizeof(struct list));
             if (par->node->degree > q->node->degree)
               {
                   l->node = q->node;
                  q = q->next;
               }
           else
               {
                  l->node = par->node;
                  par = par->next;
                 }
            l->next = NULL;
            l->prev = NULL;
            if (newl == NULL)
               newl = l;
            else
              {
                newl->next = l;
                l->prev = newl;
                newl = l;
              }
         }
       while (par)
           {
               struct list *l;
                l = (struct list *)malloc(sizeof(struct list));
                l->node = par->node;
                l->next = NULL;
                l->prev = NULL;
                par = par->next;
        if (newl == NULL)
          newl = l;
        else
         {
            newl->next = l;
            l->prev = newl;
            newl = l;
          }
       }
     while (q)
         {
            struct list *l;
            l = (struct list *)malloc(sizeof(struct list));
            l->node = q->node;
            l->next = NULL;
            l->prev = NULL;
           q = q->next;
           if (newl == NULL)
             newl = l;
          else
              {
                 newl->next = l;
                 l->prev = newl;
                 newl = l;
             }
        }
        while (newl->prev)
            newl = newl->prev;
        return newl;
    }
struct list *Union(struct list *templ1, struct list *templ2)
    {
       if (templ1 == NULL)
         return templ2;
       if (templ2 == NULL)
        return templ1;
       struct list *heap;
       heap = merge(templ1, templ2);
       struct list *par = heap;
       struct list *q = heap->next;
       while (q)
           {
              if (par->node->degree == q->node->degree)
                 {
                     if (q->next && q->node->degree == q->next->node->degree)
                        {
                           par = par->next;
                           q = q->next;
                           continue;
                         }
              if (par->node->key > q->node->key)
                 {
                    par->node->sib = q->node->child;
                    q->node->child = par->node;
                   par->node->par = q->node;
                    q->node->degree++;
                  }
              else
                 {
                    q->node->sib = par->node->child;
                    par->node->child = q->node;
                    q->node->par = par->node;
                    par->node->degree++;
                    q->node = par->node;
                }
        q->prev = par->prev;
        if (par->prev)
          {
             (par->prev)->next = q;
             par = par->next;
          }
        else
      {
       par = par->next;
       heap = par;
       }
      q = q->next;
      continue;
      }
      par = par->next;
      q = q->next;
      }
     return heap;
    }
struct BhNode *getMin(struct list *l)
    {
        if (l == NULL)
           return NULL;
        struct BhNode *mn = l->node;
        struct list *par = l;
        while (par)
          {
             if (par->node->key < mn->key)
               mn = par->node;
             par = par->next;
          }
       return mn;
    }
void printNode(struct BhNode *n)
    {
        if (n == NULL)
           return;
        printf("%d ", n->key);
        printf("(s)");
        printNode(n->sib);
        printf("(c)");
        printNode(n->child);
    }
void display(struct list *heap)
    {
       if (heap == NULL)
        return;
       struct list *l = heap;
       while (l)
        {
          printf("(r)");
          printNode(l->node);
          l = l->next;
          }
     }
struct list *DelMin(struct list *heap)
    {
        struct list *l = heap;
        struct BhNode *n = getMin(heap);
        while (l)
           {
             if (l->node->key == n->key)
               break;
             l = l->next;
             }
        if (l->prev && l->next)
          {
             l->prev->next = l->next;
             l->next->prev = l->prev;
          }
       else if (l->prev)
               {
                   l->prev->next = NULL;
                }
       else
            {
              heap = l->next;
              l->next->prev = NULL;
             }
       struct list *templ2 = NULL;
       n = n->child;
       while (n)
         {
            struct list *temp;
            temp = (struct list *)malloc(sizeof(struct list));
            temp->node = n;
            n = n->sib;
            temp->node->sib = NULL;
            temp->node->par = NULL;
            temp->next = NULL;
            temp->prev = NULL;
            if (templ2 == NULL)
             {
                 templ2 = temp;
               }
            else
               {
                  templ2->prev = temp;
                  temp->next = templ2;
                  templ2 = temp;
               }
           }
        return Union(heap, templ2);
    }
int main()
    {
        int c;
        struct list *heap;
        struct list *heap2;
        heap = NULL;
        heap2 = NULL;
        int k, n,i;
        printf("\n1.Create heap \n2.Insert \n3.Union \n4.GetMin \n5.DeleteMin \n6.Display \n7.Exit \n");
        while (1)
             {
                printf("\nEnter Choice : ");
                scanf("%d", &c);
                switch (c)
                     {
                        case 1: printf("Enter key : ");
                                    scanf("%d", &k);
                                    heap = insert(heap, k);
                                    break;
                        case 2: if (heap == NULL)
                                    printf("Heap is Empty\n");
                                    else
                                        {
                                            printf("Enter key : ");
                                            scanf("%d", &k);
                                            heap = insert(heap, k);
                                            printf("key inserted \n");
                                         }
                                    break;
                         case 3: if (heap == NULL)
                                     printf("Heap Is Empty\n");
                                     else
                                        {
                                           printf("No of element in 2nd heap : ");
                                           scanf("%d", &n);
                                           printf("Enter elements : ");
                                           for (i = 0; i < n; i++)
                                               {
                                                  scanf("%d", &k);
                                                  heap2 = insert(heap2, k);
                                                }
                                    heap = Union(heap, heap2);
                                    heap2 = NULL;
                                   printf("Union Operation Complete\n");
                                         }
                                   break;
                         case 4: if (heap == NULL)
                                       printf("Heap is Empty\n");
                                    else
                                       printf("Minimum key = %d\n", getMin(heap)->key);
                                   break;
                         case 5: if (heap == NULL)
                                         printf("Empty Heap\n");
                                     else
                                        {
                                            heap = DelMin(heap);
                                            printf("Deletion Completed\n");
                                            }
                                     break;
                        case 6: if (heap == NULL)
                                       printf("Heap is Empty\n");
                                    else
                                            display(heap);
                                    printf("\n");
                                    break;
                        case 7: exit(0);
                }
            }
        return 0;
       }
