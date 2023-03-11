
#include <iostream>
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
	std::cin >> T;
	for (int t = 0; t != T; ++t)
	{
		std::cin >> K;
		Q.clear();
		for (int k = 0; k != K; ++k)
		{
			std::string cmd;
			int value;
			std::cin >> cmd >> value;
			switch (cmd[0])
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
			std::cout << "EMPTY" << std::endl;
		else
			std::cout << (--Q.end())->first << Q.begin()->first << std::endl;
	}
	return 0;
}