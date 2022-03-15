#include <iostream>
using namespace std;

int n, m, lim;
int ary[64][64];
long long dis[64][64];

int check(int t)
{
	int i, j, k, ans;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			dis[i][j] = ary[i][j];
			if (dis[i][j] < 0)
			{
				dis[i][j] = t;
			}
		}
	}
	for (k=0; k<n; k++)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	for (i=0, ans=0; i<n; i++)
	{
		for (j=i+1; j<n; j++)
		{
			if (dis[i][j] <= m)
			{
				++ans;
			}
		}
	}
	//printf("%d: %d\n", t, ans);
	return ans;
}

int main()
{
	int i, j, c, p, q, mid, a, b;
	while (scanf("%d%d%d", &n, &m, &lim) == 3)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		for (p=1, q=m+1, b=0; p<=q; )
		{
			mid = ((p+q) >> 1);
			c = check(mid);
			if (c >= lim)
			{
				b = mid;
				p = mid+1;
			}
			else
			{
				q = mid-1;
			}
		}
		for (p=1, q=m+1, a=m+2; p<=q; )
		{
			mid = ((p+q) >> 1);
			c = check(mid);
			if (c <= lim)
			{
				a = mid;
				q = mid-1;
			}
			else
			{
				p = mid+1;
			}
		}
		if (a > b)
		{
			puts("0");
		}
		else
		{
			if (b > m)
			{
				puts("Infinity");
			}
			else
			{
				printf("%d\n", b-a+1);
			}
		}
	}
	return 0;
}
