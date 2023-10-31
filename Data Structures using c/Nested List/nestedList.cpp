// c++ program for nested list 

#include <iostream> 
#include <iterator> 
#include <list> 
using namespace std; 

void printNestedList(list<list<int> > nested_list) 
{ 
	cout << "[\n"; 

	// nested_list`s iterator(same type as nested_list) 
	// to iterate the nested_list 
	list<list<int> >::iterator nested_list_itr; 

	// Print the nested_list 
	for (nested_list_itr = nested_list.begin(); 
		nested_list_itr != nested_list.end(); 
		++nested_list_itr) { 

		cout << " ["; 

		// normal_list`s iterator(same type as temp_list) 
		// to iterate the normal_list 
		list<int>::iterator single_list_itr; 

		// pointer of each list one by one in nested list 
		// as loop goes on 
		list<int>& single_list_pointer = *nested_list_itr; 

		for (single_list_itr = single_list_pointer.begin(); 
			single_list_itr != single_list_pointer.end(); 
			single_list_itr++) { 
			cout << " " << *single_list_itr << " "; 
		} 
		cout << "]\n"; 
	} 
	cout << "]"; 
} 

// Driver code 
int main() 
{ 
	// instead integer type can have any data type 
	list<list<int> > nested_list; 
	list<int> single_list; 
	int n, m, num; 

	// number of lists in nested list 
	n = 3; 

	for (int i = 0; i < n; i++) { 

		// number of elements in list 
		m = i + 2; 
		for (int j = 0; j < m; j++) { 
			num = i + j; 
			single_list.push_back(num); 
		} 

		nested_list.push_back(single_list); 

		// delete all elements from single_list 
		single_list.erase(single_list.begin(), 
						single_list.end()); 
	} 

	printNestedList(nested_list); 

	return 0; 
} 
