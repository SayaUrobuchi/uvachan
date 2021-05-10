#include <iostream>

int tbl[128];
long long ary[128][128][128], bry[128][128], ans[128];
char s[1024];

void fix(long long &a, const long long &b)
{
	a = (a%b+b)%b;
}

long long gcd(long long a, long long b)
{
	while ((a%=b) && (b%=a));
	return a+b;
}

int main()
{
	int count, n, m, i, j, k;
	long long a, b, t;
	tbl['*'] = 0;
	for (i='a'; i<='z'; i++)
	{
		tbl[i] = i-'a'+1;
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%s", &m, s);
		for (n=0; s[n]; n++);
		for (i=1; i<=n; i++)
		{
			for (j=n-1, t=1; j>=0; j--, t=(t*i)%m)
			{
				ary[0][i-1][j] = t;
				//printf(" %lld", t);
			}
			bry[0][i-1] = tbl[s[i-1]];
			//printf(" = %lld\n", bry[0][i]);
		}
		for (i=1; i<n; i++)
		{
			for (j=0; j<n-i; j++)
			{
				a = ary[i-1][j][n-i];
				b = ary[i-1][j+1][n-i];
				t = a/gcd(a, b)*b;
				a = t/a;
				b = t/b;
				//printf("level %d => %dth:", i, j);
				for (k=0; k<n-i; k++)
				{
					ary[i][j][k] = ary[i-1][j+1][k]*b - ary[i-1][j][k]*a;
					fix(ary[i][j][k], m);
					//printf(" %lld", ary[i][j][k]);
				}
				bry[i][j] = bry[i-1][j+1]*b - bry[i-1][j]*a;
				fix(bry[i][j], m);
				//printf(" = %lld\n", bry[i][j]);
			}
		}
		for (i=n-1; i>=0; i--)
		{
			for (j=0; j<n-i-1; j++)
			{
				bry[i][0] -= ary[i][0][j] * ans[j];
				fix(bry[i][0], m);
			}
			for (j=0; j<m; j++)
			{
				if (ary[i][0][n-i-1] * j % m == bry[i][0])
				{
					ans[n-i-1] = j;
					break;
				}
			}
		}
		printf("%d", ans[n-1]);
		for (i=n-2; i>=0; i--)
		{
			printf(" %d", ans[i]);
		}
		puts("");
	}
	return 0;
}
