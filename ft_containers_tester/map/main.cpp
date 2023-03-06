
#include <cstdio>
#ifdef STD_TEST //CREATE A REAL STL EXAMPLE
	#include <map>
	namespace ft = std;
#else
	#include <map.hpp>
#endif

// My solution for BOJ 7662
// https://www.acmicpc.net/problem/7662

int main(void)
{
	ft::map<int, int>	Q;

	int T, K;
	scanf("%d\n", &T);
	for (int t = 0; t != T; ++t)
	{
		scanf("%d\n", &K);
		Q.clear();
		for (int k = 0; k != K; ++k)
		{
			char cmd;
			int value;
			scanf("%c %d\n", &cmd, &value);
			switch (cmd)
			{
				case 'I':
					Q[value]++;
					break;
				case 'D':
					if (Q.empty())
						break ;
					else if (value == 1)
					{
						ft::map<int, int>::iterator it = --Q.end();
						if (--(it->second) == 0)
							Q.erase(it);
					}
					else // value == -1
					{
						ft::map<int, int>::iterator it = Q.begin();
						if (--(it->second) == 0)
							Q.erase(it);
					}
			}
		}
		if (Q.empty())
			printf("EMPTY\n");
		else
			printf("%d %d\n", (--Q.end())->first, Q.begin()->first);
	}
	return 0;
}