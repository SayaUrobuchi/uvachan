#include <stdio.h>
#include <algorithm>

int ary[6], tbl[64];

int main()
{
	int cnt, i, j, k;
	cnt = 0;
	while (scanf("%d%d%d%d%d", &ary[0], &ary[1], &ary[2], &ary[3], &ary[4]) == 5)
	{
		if (!ary[0])
		{
			break;
		}
		++cnt;
		std::sort(ary, ary+3);
		std::sort(ary+3, ary+5);
		for (i=0; i<5; i++)
		{
			tbl[ary[i]] = cnt;
		}
		for (i=2; i>=0&&ary[3]<ary[i]; i--);
		for (j=2; j>=0&&ary[4]<ary[j]; j--);
		if (i == 2 && j == 2)
		{
			for (k=1; k<=52; k++)
			{
				if (tbl[k] != cnt)
				{
					printf("%d\n", k);
					break;
				}
			}
		}
		else if (i == 2 || j == 2)
		{
			k = (i+j==3?ary[1]:ary[2])+1;
			for (; k<=52; k++)
			{
				if (tbl[k] != cnt)
				{
					break;
				}
			}
			printf("%d\n", k>52?-1:k);
		}
		else if (i == 1 && j == 1)
		{
			k = ary[1]+1;
			for (; k<=52; k++)
			{
				if (tbl[k] != cnt)
				{
					break;
				}
			}
			printf("%d\n", k>52?-1:k);
		}
		else
		{
			puts("-1");
		}
	}
	return 0;
}
