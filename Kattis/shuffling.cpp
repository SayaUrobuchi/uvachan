#include <iostream>

int ucnt;
int ary[1024], used[1024];
char s[16];

long long gcd(long long a, long long b)
{
	while ((a%=b) && (b%=a));
	return a+b;
}

int main()
{
	int n, i, j;
	long long res, ans;
	while (scanf("%d%s", &n, s) == 2)
	{
		if (*s == 'o')
		{
			for (i=0; (i<<1)<n; i++)
			{
				ary[i] = (i<<1);
			}
			for (j=1; i<n; i++, j+=2)
			{
				ary[i] = j;
			}
		}
		else
		{
			for (i=0; ((i<<1)|1)<n; i++)
			{
				ary[i] = ((i<<1)|1);
			}
			for (j=0; i<n; i++, j+=2)
			{
				ary[i] = j;
			}
		}
		++ucnt;
		for (i=0, ans=1; i<n; i++)
		{
			if (used[i] != ucnt)
			{
				for (j=i, res=0; used[j]!=ucnt; used[j]=ucnt, j=ary[j], res++);
				ans = ans/gcd(ans, res)*res;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
