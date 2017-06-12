#include <stdio.h>
#include <string.h>

int dp[25005];
char ary[25005][18];
char buf[2008];

int bisearch(char *s, int left, int right)
{
	int center, cmp;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center /= 2;
	cmp = strcmp(ary[center], s);
	if(!cmp)
	{
		return center;
	}
	else if(cmp > 0)
	{
		return bisearch(s, left, center-1);
	}
	return bisearch(s, center+1, right);
}

int main()
{
	int n, i, ans, target;
	char *ptr;
	gets(ary[0]);
	dp[0] = 1;
	n = 1;
	ans = 0;
	while(gets(ary[n]))
	{
		for(ptr=ary[n]; *ptr; ptr++)
		{
			/* delete */
			if(*(ptr+1) <= *ptr)
			{
				sprintf(buf, "%.*s%s\0", ptr-ary[n], ary[n], ptr+1);
				/*printf("%s\n", buf);*/
				if(strcmp(buf, ary[n]) < 0)
				{
					target = bisearch(buf, 0, n-1);
					/*printf("%d\n", target);*/
					if(target != -1 && dp[target] > dp[n])
					{
						dp[n] = dp[target];
					}
				}
			}
			/* add */
			for(i='a'; i<=(*ptr); i++)
			{
				sprintf(buf, "%.*s%c%s\0", ptr-ary[n], ary[n], i, ptr);
				/*printf("%s\n", buf);*/
				if(strcmp(buf, ary[n]) < 0)
				{
					target = bisearch(buf, 0, n-1);
					/*printf("%d\n", target);*/
					if(target != -1 && dp[target] > dp[n])
					{
						dp[n] = dp[target];
					}
				}
			}
			/* change */
			strcpy(buf, ary[n]);
			for(i='a'; i<=(*ptr); i++)
			{
				buf[ptr-ary[n]] = i;
				/*printf("%s\n", buf);*/
				if(strcmp(buf, ary[n]) < 0)
				{
					target = bisearch(buf, 0, n-1);
					/*printf("%d\n", target);*/
					if(target != -1 && dp[target] > dp[n])
					{
						dp[n] = dp[target];
					}
				}
			}
		}
		dp[n++]++;
		if(dp[n-1] > ans)
		{
			ans = dp[n-1];
		}
	}
	printf("%d\n", ans);
	/*for(; ; );*/
	return 0;
}
