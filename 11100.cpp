#include <stdio.h>
#include <stdlib.h>

int ary[10005];

int comp(const void *p, const void *q)
{
	return *(int*)p > *(int*)q ? 1 : -1;
}

int main()
{
	int cnt, n, i, j, ans;
	cnt = 0;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		for (i=0; i<n; ++i)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary, n, sizeof(ary[0]), comp);
		ans = 0;
		for (i=0; i<n; i=j)
		{
			for (j=i+1; j<n&&ary[i]==ary[j]; ++j);
			if (j-i > ans)
			{
				ans = j-i;
			}
		}
		if (!cnt)
		{
			puts("");
		}
		printf("%d\n", ans);
		for (i=0; i<ans; i++)
		{
			printf("%d", ary[i]);
			for (j=i+ans; j<n; j+=ans)
			{
				printf(" %d", ary[j]);
			}
			puts("");
		}
	}
	return 0;
}
