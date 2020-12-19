#include <iostream>
#include <algorithm>

int ary[1048576];

int main()
{
	int count, n, i, j, t, u;
	long long k;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			for (j=0, k=0; j<t; j++)
			{
				scanf("%d", &u);
				k += u;
			}
			ary[i] = k;
		}
		std::sort(ary, ary+n);
		for (i=0, t=0, k=0; i<n; i++)
		{
			k += t += ary[i];
		}
		printf("%.10lf\n", (double)k/n);
	}
	return 0;
}
