#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *next;
};
struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;
struct node *this = NULL;
struct node *insert(struct node **head, int data){
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    if(*head==NULL)
        *head=p;
    else
        this->next=p;

    return p;
}
void printlist(struct node *ptr){
    while(ptr!=NULL){
        printf("%d\t", ptr->data);
        ptr=ptr->next;
    }
    printf("\n\n");
}
struct node *prod(struct node **ptr1, struct node **ptr2, int min){
    int i, prod=0;
        for(i=0; i<min; i++){
        prod=((*ptr1)->data)*((*ptr2)->data);
        this=insert(&head3, prod);
        (*ptr1)=(*ptr1)->next;
        (*ptr2)=(*ptr2)->next;
    }
    if((*ptr1)!=NULL)
        return (*ptr1);
    else
        return (*ptr2);
}
int length(struct node *ptr){
    int l=0;
    for(; ptr!=NULL; ptr=ptr->next)
        l++;
    return l;
}

void main(){
    struct node *newNode;
    char a='y';
    int val, min;
    printf("Linked List 1:\n\n");
    while(a=='y'){
        printf("Element: ");
        scanf("%d", &val);
        this=insert(&head1, val);
        printf("Enter more?[y/n]: ");
        scanf("%s", &a);

    }

    printf("\n\nLinked List 2:\n\n");
    a='y';
    while(a=='y'){
        printf("Element: ");
        scanf("%d", &val);
        this=insert(&head2, val);
        printf("Enter more?[y/n]: ");
        scanf("%s", &a);
    }

    printf("\nLinked List 1: ");
    printlist(head1);

    printf("\nLinked List 2: ");
    printlist(head2);

    int m=length(head1);
    int n=length(head2);

    if(m<n){
        min=m;
        newNode=prod(&head1, &head2, min);
        while(newNode!=NULL){
            this=insert(&head3, newNode->data);
            newNode=newNode->next;
        }
    }
    else{
        min=n;
        newNode=prod(&head1, &head2, min);
        while(newNode!=NULL){
            this=insert(&head3, newNode->data);
            newNode=newNode->next;
        }
    }
printf("Product LL: ");
    printlist(head3);
}
