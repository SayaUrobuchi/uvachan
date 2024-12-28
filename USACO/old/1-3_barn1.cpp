/*
ID: sa072682
LANG: C
TASK: barn1
*/
#include <stdio.h>
#include <stdlib.h>

int ary[200];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int m, s, c, i, j, ans;
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	scanf("%d%d%d", &m, &s, &c);
	m--;
	for(i=0; i<c; i++)
	{
		scanf("%d", &ary[i]);
	}
	qsort(ary, c, sizeof(int), comp);
	ans = ary[c-1] - ary[0] + 1;
	for(i=c-1; i; i--)
	{
		ary[i] -= ary[i-1] + 1;
	}
	qsort(ary+1, c-1, sizeof(int), comp);
	if(m)
	{
		for(i=c-1; i; i--)
		{
			ans -= ary[i];
			m--;
			if(!m)
			{
				break;
			}
		}
	}
	printf("%d\n", ans);
	scanf(" ");
	return 0;
}
