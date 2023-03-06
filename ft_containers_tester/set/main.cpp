#include <cstdio>
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
	scanf("%d\n", &N);
	ft::set<int> set;
	for (int n = 0; n != N; ++n)
	{
		int data;
		scanf("%d\n", &data);
		set.insert(data);
	}
	for (ft::set<int>::iterator iter = set.begin(); iter != set.end(); ++iter)
		printf("%d\n", *iter);
	return 0;
}
