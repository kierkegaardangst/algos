#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

template <typename T, typename Key>

struct list
{
	
};

void list_search(list<T> L, Key k)
{
	
}

int main()
{
	
	return 0;
}
/*
Linked List: Unsorted and Doubly-Linked
Add new element at the beginning O(1)
Add new element at the position k <= n O(n) 
	Deslocate until element k-1
	Point element k-1 to k and k to k+1 or null
Find element k or specific data - O(n)
Delete element k or data from list 
Destroy List 	
	destroy elements from the beginnign of the list and keep
	changing the head pointer to point to the first element
	go on destroying
*/
