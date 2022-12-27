#include <iostream>
using namespace std;

int ary[262144];

int main()
{
	int n, i, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d", &t);
			ary[t] = i;
		}
		printf("%d", ary[1]);
		for (i=2; i<=n; i++)
		{
			printf(" %d", ary[i]);
		}
		puts("");
	}
	return 0;
}

