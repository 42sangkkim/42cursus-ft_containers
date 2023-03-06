#include <cstdio>
#ifdef STD_TEST //CREATE A REAL STL EXAMPLE
	#include <vector>
	namespace ft = std;
#else
	#include <vector.hpp>
#endif

// My solution for BOJ 9465
// https://www.acmicpc.net/problem/9465

int main ( void )
{
	int T, n;

	scanf("%d\n", &T);
	for (int t = 0; t != T; ++t)
	{
		scanf("%d\n", &n);
		ft::vector<int> sticker[3];
		sticker[0].resize(n);
		sticker[1].resize(n);
		sticker[2].resize(n);
		for (int i = 0; i != n; ++i)
			scanf("%d", &sticker[0][i]);
		scanf("\n");
		for (int i = 0; i != n; ++i)
			scanf("%d", &sticker[1][i]);
		scanf("\n");
		sticker[2][0] = 0;
		for (int i = 0; i != n - 1; ++i)
		{
			sticker[0][i + 1] += (sticker[1][i] > sticker[2][i] ? sticker[1][i] : sticker[2][i]);
			sticker[1][i + 1] += (sticker[0][i] > sticker[2][i] ? sticker[0][i] : sticker[2][i]);
			sticker[2][i + 1] = (sticker[0][i] > sticker[1][i] ? sticker[0][i] : sticker[1][i]);
		}
		if (sticker[0][n - 1] > sticker[1][n - 1])
			printf("%d\n", sticker[0][n - 1]);
		else
			printf("%d\n", sticker[1][n - 1]);
	}
	return 0;
}
