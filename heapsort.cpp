#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

void heapify(vector<int> &v, int heap_size, int i)
{
	int left = 2*i + 1;
	int right = 2*i + 2;
	int max = i;
	if (left < heap_size && v[left] > v[max]) max = left;
	if (right < heap_size && v[right] > v[max]) max = right;
	if (max != i)
	{
		swap(v[i], v[max]);
		heapify(v, heap_size, max);
	}
}

void buildheap(vector<int> &v)
{
	for (int i = v.size()/2; i >= 0; i--)
	{
		heapify(v, v.size(), i);
	}
}

void heapsort(vector<int> &v)
{
	buildheap(v);
	int heap_size = v.size();
	for (int i = v.size() - 1; i > 0; i--)
	{
		swap(v[i], v[0]);        
		heap_size = heap_size - 1; 
		heapify(v, heap_size, 0);           
	}
}

int main()
{
	std::vector<int> v = {16,14,10,8,7,9,3,2,4,1};
	heapsort(v);
	for (auto vv : v) cout << vv << " ";
	return 0;
}

/* 

Heapify
	Construir Heap - Árvore Binária
	Pai maior que os filhos
	Os filhos ficam em v[2*i+1] e v[2*i+2]
	Recursivamente, vai selecionando os maiores elementos
	para ficarem como pais no topo da árvore.
	if max changes, it has found a new great element to become a parent
	in the binary tree

Buildheap
	Builds the heap binary tree (v[i]>v[2i+1] v[i]>v[2i+2]) out of a vector
	Builds only for half of the tree with parent nodes,
	the other half are leaves and they dont have 2i+1 and 2i+2 positions
	to satisfact the property of a heap.
	
Heapsort
	O maior elemento no topo vira o último
	The size is decremented to isolate the last great element
	Call heapify again to find the other greates element
	Goes from v.size()-1 down to 1, leaving v[0] out 
*/
