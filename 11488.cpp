#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stk[100005], loc[100005];
char *str[50005], buf[50005][205];

int comp(const void *p, const void *q)
{
	return strcmp(*(char**)p, *(char**)q);
}

int main()
{
	int count, n, i, j, tp, ans, temp, len;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s", buf[i]);
			str[i] = buf[i];
		}
		qsort(str, n, sizeof(char*), comp);
		stk[0] = strlen(str[0]);
		loc[0] = 0;
		for(i=1, tp=0, ans=0; i<n; i++)
		{
			len = strlen(str[i]);
			for(j=0; str[i-1][j]&&str[i][j]; j++)
			{
				if(str[i-1][j] != str[i][j])
				{
					break;
				}
			}
			for(temp=i; tp>=0; tp--)
			{
				if(j > stk[tp])
				{
					break;
				}
				if((i-loc[tp]) * stk[tp] > ans)
				{
					ans = (i-loc[tp]) * stk[tp];
				}
				temp = loc[tp];
			}
			stk[++tp] = j;
			loc[tp] = temp;
			if(j < len)
			{
				stk[++tp] = len;
				loc[tp] = i;
			}
		}
		for(; tp>=0; tp--)
		{
			if((i-loc[tp]) * stk[tp] > ans)
			{
				ans = (i-loc[tp]) * stk[tp];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
