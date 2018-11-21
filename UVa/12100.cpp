#include <stdio.h>

int tbl[16], ary[16384];

int main()
{
	int count, n, m, i, j, mx, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (i=0; i<=10; i++)
		{
			tbl[i] = 0;
		}
		mx = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			tbl[ary[i]]++;
			if (ary[i] > mx)
			{
				mx = ary[i];
			}
		}
		ans = 1;
		for (i=0, j=n; i<j; i++)
		{
			if (ary[i] == mx)
			{
				tbl[mx]--;
				if (i == m)
				{
					break;
				}
				++ans;
				if (!tbl[mx])
				{
					for (; mx>0&&!tbl[mx]; mx--);
				}
			}
			else
			{
				ary[j] = ary[i];
				if (i == m)
				{
					m = j;
				}
				j++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
