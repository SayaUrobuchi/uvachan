#include <iostream>
using namespace std;

const int M = 2019;

int main()
{
	int a, b, i, j;
	scanf("%d%d", &a, &b);
	int best = M;
	for (i=a; i<b&&i<a+M; i++)
	{
		for (j=i+1; j<=b&&j<=i+M; j++)
		{
			best = min(best*1LL, i*1LL*j%M);
		}
	}
	printf("%d\n", best);
	return 0;
}
