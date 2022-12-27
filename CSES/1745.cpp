#include <iostream>
#include <algorithm>
using namespace std;

int ary[1000050];

int main()
{
	int n, i, j, k, t;
	while (scanf("%d", &n) == 1)
	{
		ary[0] = 0;
		for (i=0, t=1; i<n; i++)
		{
			scanf("%d", &k);
			for (j=0; j<t; j++)
			{
				ary[j+t] = ary[j] + k;
			}
			inplace_merge(ary, ary+t, ary+t+t);
			t = unique(ary, ary+t+t) - ary;
		}
		printf("%d\n%d", t-1, ary[1]);
		for (i=2; i<t; i++)
		{
			printf(" %d", ary[i]);
		}
		puts("");
	}
	return 0;
}

