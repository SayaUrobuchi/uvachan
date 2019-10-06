#include <stdio.h>

int ary[16384], tbl[32768];

int main()
{
	int count, ucnt, i, j, n, m;
	ucnt = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		ucnt++;
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			for (j=0; j<i&&ary[i]; j++)
			{
				if (ary[j])
				{
					tbl[ary[i]+ary[j]] = ucnt;
				}
			}
		}
		scanf("%d", &m);
		while (m--)
		{
			scanf("%d", &i);
			if (i <= 30000 && tbl[i] == ucnt)
			{
				puts("Good!");
			}
			else
			{
				puts("So Bad!");
			}
		}
	}
	return 0;
}
