/*
ID: sa072682
LANG: C
TASK: milk
*/
#include <stdio.h>
#include <stdlib.h>

int price[5001], provide[5001], ary[5001];

int comp(const void *p, const void *q)
{
	return price[*(int*)p] - price[*(int*)q];
}

int main()
{
	int n, m, i, j, ans;
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(i=0; i<m; i++)
	{
		scanf("%d%d", &price[i], &provide[i]);
		ary[i] = i;
	}
	qsort(ary, m, sizeof(int), comp);
	for(i=0, ans=0; ; i++)
	{
		j = ary[i];
		if(provide[j] >= n)
		{
			ans += n * price[j];
			break;
		}
		else
		{
			ans += price[j] * provide[j];
			n -= provide[j];
		}
	}
	printf("%d\n", ans);
	scanf(" ");
	return 0;
}
