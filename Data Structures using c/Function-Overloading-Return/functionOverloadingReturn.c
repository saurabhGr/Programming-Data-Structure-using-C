// CPP Program to demonstrate that function overloading 
// fails if only return types are different 
#include <iostream> 
int fun() { return 10; } 

char fun() { return 'a'; } 
// compiler error as it is a new declaration of fun() 

// Driver Code 
int main() 
{ 
	char x = fun(); 
	getchar(); 
	return 0; 
}
