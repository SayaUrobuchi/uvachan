#include <iostream>
using namespace std;

int ary[1048576];

int main()
{
	int n, m, i, j, best;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, j=0, best=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			for (; j<n&&ary[i]-ary[j]>=1000; j++);
			best = max(best, i-j+1);
		}
		printf("%d\n", (best-1)/m+1);
	}
	return 0;
}
