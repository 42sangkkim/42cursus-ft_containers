#include <iostream>
#ifdef STD_TEST //CREATE A REAL STL EXAMPLE
	#include <set>
	namespace ft = std;
#else
	#include <set.hpp>
#endif

// My solution for BOJ 1927
// https://www.acmicpc.net/problem/1927

int main ( void )
{
	int N;
	std::cin >> N;
	ft::set<int> set;
	for (int n = 0; n != N; ++n)
	{
		int data;
		std::cin >> data;
		set.insert(data);
	}
	for (ft::set<int>::iterator iter = set.begin(); iter != set.end(); ++iter)
		std::cout << *iter << std::endl;
	return 0;
}
