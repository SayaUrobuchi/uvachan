/*
	ID: sa072682
	LANG: C
	TASK: fence
*/
#include <stdio.h>
#include <stdlib.h>

short stack[1025], map[501][1025], num[501], c[501][501], ary[501], l;

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

void recursion(int now)
{
	int i;
	for(; ary[now]<num[now]; ary[now]++)
	{
		if(c[now][map[now][ary[now]]])
		{
			c[now][map[now][ary[now]]]--;
			c[map[now][ary[now]]][now]--;
			ary[now]++;
			recursion(map[now][ary[now]-1]);
			ary[now]--;
		}
	}
	stack[l++] = now;
}

int comp(const void *p, const void *q)
{
	return *(short*)p - *(short*)q;
}

int main()
{
	int n, m, i, j, s;
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	scanf("%d", &m);
	n = 1;
	while(m--)
	{
		scanf("%d%d", &i, &j);
		map[i][num[i]++] = j;
		map[j][num[j]++] = i;
		c[i][j]++;
		c[j][i]++;
		n = max(n, max(i, j));
		if(i == j)
		{
			printf("i == j\n");
		}
	}
	for(i=n, s=1; i; i--)
	{
		if(num[i] % 2)
		{
			s = i;
		}
		qsort(map[i], num[i], sizeof(short), comp);
	}
	recursion(s);
	for(i=l-1; i>-1; i--)
	{
		printf("%d\n", stack[i]);
	}
	scanf(" ");
	return 0;
}
