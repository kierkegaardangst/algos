#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

// Linked List 
template <typename Key>
struct Node
{
	Key key; // data / key inside the node (int = 1, string="Soren")
	Node *next;
	Node *prev;
	
	Node(Key k) : key(k), next(nullptr), prev(nullptr) {}
};

template <typename Key>
struct List
{
	Node<Key> *head; // First node element with node->prev and node->next

	List() : head(nullptr) {}
};
// --------------------------------------------

// Insert: Starts the Linked List
template <typename Key>
void list_insert(List<Key>& L, Node<Key>* x)
{
	x->next = L.head;
	if (L.head != nullptr)
	{
		L.head->prev = x;
	}
	L.head = x;
	x->prev = nullptr;
}

// Search
template <typename Key>
Node<Key>* list_search(List<Key>& L, Key k) 
{
	Node<Key> *x = L.head;
	while (x != nullptr && x->key != k)
	{
		x = x->next;
	}
	return x;
}

// Delete
template<typename Key>
void list_delete(List<Key>& L, Node<Key>* x)
{
	if (x->prev != nullptr)
	{
		x->prev->next = x->next;
	} 
	else
	{
		L.head = x->next;
	}
	
	if (x->next != nullptr)
	{
		x->next->prev = x->prev;
	}
}

// Size
template <typename Key>
int list_size(List<Key>& L)
{
    int count = 0;
    Node<Key>* x = L.head;
    
    while (x != nullptr)
    {
        count++;
        x = x->next;
    }
    return count;
}

int main()
{
	List<int> l;

	Node<int>* n1 = new Node<int>(65);
	Node<int>* n2 = new Node<int>(32);
	Node<int>* n3 = new Node<int>(70);

	list_insert(l, n1);
	list_insert(l, n2);
	list_insert(l, n3);

    cout << "List 1 size: " << list_size(l) << endl;

    cout << "List 1: ";
    Node<int>* x = l.head;
    while (x != nullptr) 
    {
        cout << x->key << " ";
        x = x->next;
    }
    cout << endl;
    
    Node<int>* node_delete = list_search(l, 32);
    if (node_delete != nullptr)
    {
		cout << "Deleted element with data-key: " << node_delete->key << endl;
        list_delete(l, node_delete);
        delete node_delete;
    } else{
		cout << "Node not found inside the linked list." << endl;
	}
    
    cout << "List 1: ";
    x = l.head;
    while (x != nullptr) 
    {
        cout << x->key << " ";
        x = x->next;
    }
    cout << endl;

	// ------------------------

	List<string> l2;

	Node<string>* n4 = new Node<string>("Soren");
	Node<string>* n5 = new Node<string>("Huxley");
	Node<string>* n6 = new Node<string>("Lovecraft");
	Node<string>* n7 = new Node<string>("Yeats");

	list_insert(l2, n4);
	list_insert(l2, n5);
	list_insert(l2, n6);
	list_insert(l2, n7);

	cout << "List 2 size: " << list_size(l2) << endl;

    cout << "List 2: ";
    Node<string>* x_2 = l2.head;
    while (x_2 != nullptr) 
    {
        cout <<  x_2->key << " | ";
        x_2 = x_2->next;
    }
    cout << endl;


	return 0;
}
/*
	Linked List - Unsorted Doubly Linked

	* List Search - O(n)
	  - Uses the key k (data inside the node) to find the node
	  - Iterates linearly through the list to find the node containing key 'k'.
	  - Returns a pointer to the node or nullptr if not found.

	* List Insert - O(1)
	  - Insert a new node to the front of the list, making it the new head.
	  - L.head->next is never modified to not break the link
	    1. x->next points to the old head.
	    2. If the list is not empty (L.head != nullptr), the old head->prev points to x.
	    3. The L.head is updated to point to x.
	    4. x->prev points to nullptr (since it is now the first element).
	  
	    list_insert(l2, n6); // Inserts "Lovecraft"
	    List state becomes: [Head] -> "Lovecraft" -> "Aldous Huxley" -> "Soren"

	* List Delete - O(1)
	  - Bypasses node 'x' by linking its previous and next nodes together.
	  - Time complexity is O(1) assuming the pointer to node 'x' is already known.
	  - Note: If list_search must be called first to find 'x', the total time is O(n).

	Node
	
	* key / data:
	  - Holds the actual value (e.g., int = 1, string = "Soren").
	  - Example: Node<string>* x = new Node<string>("Soren");
	  - To return the data inside the node, dereference the pointer using 
	    either (*x).key or the standard arrow shorthand: x->key.

	* Pointers:
	  - x->next: Stores the memory address of the next Node in the sequence.
	  - x->prev: Stores the memory address of the previous Node in the sequence.
*/