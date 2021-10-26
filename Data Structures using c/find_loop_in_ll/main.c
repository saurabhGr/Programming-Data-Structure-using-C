#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char data;
    struct node *next;
};
struct node *head =NULL,*pre=NULL;
void printlist(){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%c\t", ptr->data);
        ptr=ptr->next;
    }
    printf("\n\n");
}
void insert(char data){
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    if(head==NULL)
        head=p;
    else
        pre->next=p;
    pre=p;
}
int findloop(){
    struct node *ptr1=head;
    struct node *ptr2=head->next;

    while(ptr1->data != ptr2->data){
        printf("[%c, %c] ", ptr1->data, ptr2->data);
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
    }
    printf("[%c, %c] ", ptr1->data, ptr2->data);
    printf("\n\nThe loop is at %c.\n", ptr1->data);
    if(ptr1->data == ptr2->data)
        return 1;
    else
        return 0;
}
void main(){
    char string[50];
    printf("Enter string: ");
    scanf("%s", string);
    int n = strlen(string),i;
    for(i=0; i<n; i++)
        insert(string[i]);
    printf("\nEntered list:\n");
    printlist();
    pre->next = head->next->next->next;
    if(findloop())
        printf("Loop Found\n\n");
    else
        printf("Loop not Found\n");
}
