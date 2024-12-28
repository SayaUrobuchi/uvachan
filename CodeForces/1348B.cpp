#include <stdio.h>

const int N = 16384;

int used[N], ucnt;
int ary[N], bry[N], cry[N];

int main()
{
	int count, n, m, i, j, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		ucnt++;
		for (i=0, t=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			if (used[ary[i]] != ucnt)
			{
				bry[t] = ary[i];
				t++;
				used[ary[i]] = ucnt;
			}
		}
		if (t > m)
		{
			puts("-1");
			continue;
		}
		for (i=1; t<m; i++)
		{
			if (used[i] != ucnt)
			{
				bry[t] = i;
				t++;
			}
		}
		for (i=0, j=0; j<n; i++)
		{
			cry[i] = bry[i%t];
			if (cry[i] == ary[j])
			{
				j++;
			}
		}
		printf("%d\n%d", i, cry[0]);
		for (j=1; j<i; j++)
		{
			printf(" %d", cry[j]);
		}
		puts("");
	}
	return 0;
}
