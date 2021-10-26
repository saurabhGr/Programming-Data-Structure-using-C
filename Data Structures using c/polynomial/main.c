#include <stdio.h>
#include <stdlib.h>
struct Node
        {int coeff;
          int power;
          struct Node *next;
        };
void create(struct Node **temp,int x,int y)
{
    struct Node *t,*c;
    t=*temp;
    if(!t)
    {
        c=(struct Node *)malloc(sizeof(struct Node));
        c->coeff=x;
        c->power=y;
        *temp=c;
        c->next=(struct Node *)malloc(sizeof(struct Node));
        c=c->next;
        c->next=NULL;
    }
    else{
        c->coeff=x;
        c->power=y;
        c->next=(struct Node *)malloc(sizeof(struct Node));
        c=c->next;
        c->next=NULL;
    }
}
void Display(struct Node *start)
{
    while(start->next)
        {printf("%dx^%d",start->coeff,start->power);
         start=start->next;
         if(start->next)
            printf("+");
        }
}
int main()
{int n,x,c1,p1;
struct Node *start=NULL;
    printf("Enter Total terms in your Polynomial\n");
    scanf("%d",&n);
    x=n;
    while(x>0)
    {printf("Enter coefficient fallowed by Power\n");
        scanf("%d%d",&c1,&p1);
        create(&start,c1,p1);
        x--;
    }
    Display(start);
    return 0;
}
