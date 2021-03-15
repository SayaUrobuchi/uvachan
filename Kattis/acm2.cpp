#include <iostream>
#include <algorithm>

const int M = 300;

int ary[128];

int main()
{
	int n, m, i, sum, pen;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::swap(ary[0], ary[m]);
		std::sort(ary+1, ary+n);
		for (i=0, sum=0, pen=0; i<n&&(sum+=ary[i])<=M; pen+=sum, ++i);
		printf("%d %d\n", i, pen);
	}
	return 0;
}
