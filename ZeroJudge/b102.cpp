#include <stdio.h>
#include <string.h>

int tbl[1000005], ary[25];

int main()
{
	int n, i, j, len, total, cnt;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		memset(tbl, 0, sizeof(tbl));
		for(i=0, total=0, cnt=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			total += ary[i];
			for(j=i, len=0; j>=0; j--)
			{
				len += ary[j];
				if(tbl[len] == 0)
				{
					tbl[len] = 1;
					cnt++;
				}
			}
		}
		if(total != n && cnt == total)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
