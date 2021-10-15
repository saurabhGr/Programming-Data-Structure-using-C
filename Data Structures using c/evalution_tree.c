#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define SIZE 100

char op_stack[SIZE];
int num_stack[SIZE];
int op_top = -1, num_top = -1;

typedef struct node
{
	int flg;
	int num;
	struct node *next;
} node;

struct tree_node{
    struct tree_node *left, *right;
	int flg;
    int data;
} *root = NULL;


typedef struct stack_node{
	struct tree_node *addr;
	struct stack_node *next;
}STACK;


STACK *top=NULL;
node *HEAD = NULL;


int is_adr_empty(){
	if(top==NULL)
		return 1;
	else
		return 0;
}

int adr_push(struct tree_node *input){
	STACK *element = (STACK*)malloc(sizeof(STACK));
	if(element == NULL){
		printf("\n\t STACK IS FULL!!");
		return 0;
	}else{
		element->addr=input;
		if(top==NULL){
			top=element;
			top->next=NULL;
		}else{
			element->next=top;
			top=element;
		}
		return 1;
	}
}


struct tree_node* adr_pop(){
	if(is_adr_empty()){
		printf("\n\tSTACK IS EMPTY!");
		return NULL;
	}else{
		struct tree_node *item = top->addr;

		STACK *del = top;
		top = top->next;
		del->next = NULL;
		free(del);

		return item;
	}
}


int insert(int value, int flag)
{
	node *p = (node *)malloc(sizeof(node));
	p->next = NULL;
	p->flg = flag;
	p->num = value;

	if (HEAD == NULL)
	{
		HEAD = p;
		p = NULL;
	}
	else
	{
	
		node *temp = HEAD;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = p;
		p = NULL;
		temp = NULL;
	}
	return 1;
}

int buildexpressiontree()
{
	if (HEAD == NULL)
	{
		printf("\n\tLIST IS EMPTY!!");
		return 0;
	}
	else
	{
		node *temp = HEAD;

		while (temp != NULL)
		{
			if (temp->flg){
			
                struct tree_node* new_node = (struct tree_node*)malloc(sizeof(struct tree_node));
				new_node->data=temp->num;
				new_node->flg=temp->flg;
				new_node->left=NULL;
				new_node->right=NULL;

			
				struct tree_node* r = adr_pop();
				struct tree_node* l = adr_pop();

				
				new_node->left=l;
				new_node->right=r;

				
				adr_push(new_node);

            }
			else{
    
                struct tree_node* new_node = (struct tree_node*)malloc(sizeof(struct tree_node));
				new_node->data=temp->num;
				new_node->flg=temp->flg;
				new_node->left=NULL;
				new_node->right=NULL;

			
				adr_push(new_node);
            }
			temp = temp->next;
		}
		return 1;
	}
}

int is_numstk_full()
{
	if (num_top == SIZE - 1)
		return 1;
	else
		return 0;
}

int is_numstk_empty()
{
	if (num_top == -1)
		return 1;
	else
		return 0;
}


void push_numstk(int item)
{
	if (is_numstk_full())
	{
		printf("\n\tSTACK OVERFLOW!");
		return;
	}
	num_stack[++num_top] = item;
}


int pop_numstk()
{
	if (is_numstk_empty())
	{
		printf("\n\tSTACK UNDERFLOW!");
		return -1;
	}
	return num_stack[num_top--];
}
int is_opstk_empty()
{
	if (op_top == -1)
		return 1;
	else
		return 0;
}

int is_opstk_full()
{
	if (op_top == SIZE - 1)
		return 1;
	else
		return 0;
}

void push_opstk(char item)
{
	if (is_opstk_full())
	{
		printf("\n\t OP STACK OVERFLOW!");
		return;
	}
	op_stack[++op_top] = item;
}

char pop_opstk()
{
	if (is_opstk_empty())
	{
		printf("\n\t OP STACK UNDERFLOW!");
		return -1;
	}
	return op_stack[op_top--];
}


char get_top()
{
	if (is_opstk_empty())
	{
		return 0;
	}
	else
	{
		return op_stack[op_top];
	}
}

int get_precedence(char ch)
{
	switch (ch)
	{
	case '^':
		return 3;
	case '*':
		return 2;
	case '/':
		return 2;
	case '+':
		return 1;
	case '-':
		return 1;
	default:
		return 0;
	}
}

int is_operator(char ch)
{
	if (
		ch == '^' ||
		ch == '+' ||
		ch == '-' ||
		ch == '*' ||
		ch == '/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void infix_to_postfix(char *infix)
{
	for (int i = 0; i < strlen(infix); i++)
	{

		if (isdigit(infix[i]))
		{
			int d = infix[i] - '0';
			
			while (isdigit(infix[i + 1]))
			{
				d *= 10;
				d += infix[i + 1] - '0';
				i++;
			}
			insert(d, 0);
		}
		else
		{
		
			if (is_opstk_empty())
			{
				push_opstk(infix[i]);
			}
			else
			{
				
				if (infix[i] == '(')
				{
					push_opstk(infix[i]);
				}
			
				else if (infix[i] == ')')
				{
					while (get_top() != '(')
					{
						insert(pop_opstk(), 1);
					}
					pop_opstk();
				}
				else
				{
				
					if (get_precedence(get_top()) == get_precedence(infix[i]))
					{
						while (get_precedence(get_top()) == get_precedence(infix[i]))
						{
							insert(pop_opstk(), 1);
						}
						push_opstk(infix[i]);
					}
				
					else if (get_precedence(get_top()) < get_precedence(infix[i]))
					{
						push_opstk(infix[i]);
					}
				
					else if (get_precedence(get_top()) > get_precedence(infix[i]))
					{
						while (get_precedence(get_top()) > get_precedence(infix[i]))
						{
							insert(pop_opstk(), 1);
						}
						push_opstk(infix[i]);
					}
				}
			}
		}
	}
	while (!is_opstk_empty())
	{
		insert(pop_opstk(), 1);
	}
}

void valid(char* infix){
	for (int i = 0; i < strlen(infix); i++){

		if(!isdigit(infix[i])&&!is_operator(infix[i])){
	
			if(infix[i] !='(' && infix[i] !=')'){
				printf("Invalid");
				exit(0);
			}
		}
	}
}


int eval_exp_tree(struct tree_node* root){
	if(root==NULL) return 0;

	if(root->right==NULL && root->left==NULL) return root->data;

	int left_value = eval_exp_tree(root->left);
	int right_value = eval_exp_tree(root->right);

	switch (root->data)
	{
		case '^':
			return (pow(left_value, right_value));
		case '*':
			return (left_value * right_value);
		case '/':
			return (left_value / right_value);
		case '+':
			return (left_value + right_value);
		case '-':
			return (left_value - right_value);
		default:
			printf("ERROR");
			break;
	}
}

int main()
{

	
	char infix[SIZE];
	scanf("%s",infix);
  valid(infix);

	infix_to_postfix(infix);

	
	buildexpressiontree();

	printf("\n");
	printf("%d", eval_exp_tree(adr_pop()));
	printf("\n\n");

	return 0;
}
