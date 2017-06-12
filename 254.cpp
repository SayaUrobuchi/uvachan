#include <stdio.h>
#include <string.h>

#define BASE 1000000000

int a, b, c;
int l[101];
int dp[101][50];
int num[50];
char buf[101];

int compare(int *a1, int l1, int *a2, int l2)
{
	int i;
	if(l1 > l2)
	{
		return 1;
	}
	else if(l1 == l2)
	{
		for(i=l1-1; i>=0; i--)
		{
			if(a1[i] > a2[i])
			{
				return 1;
			}
			else if(a1[i] < a2[i])
			{
				return -1;
			}
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

void recursion(int n, int *ary, int len)
{
	int i;
	/*printf("%d: %d", n, ary[len-1]);
	for(i=len-2; i>=0; i--)
	{
		printf("%09d", ary[i]);
	}
	printf("\n");*/
	if(!n)
	{
		a = b = c = 0;
		return;
	}
	if(compare(ary, len, dp[n-1], l[n-1]) < 0)
	{
		recursion(n-1, ary, len);
		a++;
		/*printf("%d %d %d\n", a, b, c);*/
	}
	else
	{
		ary[0]++;
		for(i=0; i<l[n]; i++)
		{
			ary[i] = dp[n][i] - ary[i];
			if(ary[i] < 0)
			{
				ary[i] += BASE;
				ary[i+1]++;
			}
		}
		for(len--; len>=0&&!ary[len]; len--);
		len++;
		recursion(n-1, ary, len);
		if(n % 2)
		{
			i = a;
			a = b;
			b = i;
			b++;
		}
		else
		{
			i = a;
			a = c;
			c = i;
			/*printf("%d %d %d\n", a, b, c);*/
			c++;
		}
	}
}

int main()
{
	int n, i, j;
	l[0] = 1;
	dp[0][0] = 1;
	for(i=1; i<=100; i++)
	{
		for(j=0; j<l[i-1]; j++)
		{
			dp[i][j] += (dp[i-1][j] << 1);
			if(dp[i][j] >= BASE)
			{
				dp[i][j] -= BASE;
				dp[i][j+1]++;
			}
		}
		l[i] = l[i-1];
		if(dp[i][l[i]])
		{
			l[i]++;
		}
		/*printf("%d", dp[i][l[i]-1]);
		for(j=l[i]-2; j>=0; j--)
		{
			printf("%09d", dp[i][j]);
		}
		printf("\n");*/
	}
	while(scanf("%d%s", &n, buf) == 2)
	{
		if(!n && !strcmp(buf, "0"))
		{
			break;
		}
		for(i=0, j=strlen(buf)-9; j>0; i++, j-=9)
		{
			sscanf(buf+j, "%9d", &num[i]);
		}
		buf[j+9] = 0;
		sscanf(buf, "%d", &num[i++]);
		/*printf("%d", num[i-1]);
		for(j=i-2; j>=0; j--)
		{
			printf("%09d", num[j]);
		}
		printf("\n");*/
		recursion(n, num, i);
		printf("%d %d %d\n", a, b, c);
	}
	return 0;
}
