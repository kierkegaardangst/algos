#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>
#include <initializer_list>

using namespace std;

template<typename T = int, int N = 3>
class Array
{
	private:
		T m_Array[N];
	public:
		// Array() : T(int), N(3) {}
		// Array(arraytype, size) : T(arraytype), N(size) {}
		Array() : m_Array{} {}
		int getsize() { return N; }
};
/*
 * templates are compile-time, cannot use member initializer list
 * template<int N> expects a value (like 5 or 10).
 * template<typename N> expects a data type (like int, float, or string)
*/

class Array2
{
	private:
		vector<int> m_Array;
		
	public:
		Array2() : m_Array{0,0,0} {}
		Array2(vector<int> v) : m_Array(v) {} 
		Array2(initializer_list<int> list) : m_Array(list) {}
		
		auto begin() { return m_Array.begin(); }
		auto end()   { return m_Array.end(); }
};

int main()
{
	Array array;
	cout << array.getsize() << endl;
	
	Array<string, 5> a{};
	cout << a.getsize() << endl;
	
	Array2 array2;
	for(auto elem: array2) cout << elem << " ";
	cout << endl;
	
	vector<int> v = {1,2,3,4,5};
	Array2 a2(v);
	for(auto elem : a2){
		cout << elem << " ";
	} 
	cout << endl;
	
	Array2 a3 = {1,2,3,4,5};
	for (auto elem : a3) cout << elem << " ";
	
	return 0;
}
