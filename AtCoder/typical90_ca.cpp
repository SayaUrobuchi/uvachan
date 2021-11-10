#include <iostream>
using namespace std;

int dx[] = {0, 0, 1, 1};
int dy[] = {0, 1, 0, 1};

int bry[128][128];
long long ary[128][128];

int main()
{
	int n, m, i, j, k;
	long long ans, t;
	bool ok;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				scanf("%lld", &ary[i][j]);
			}
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				scanf("%d", &bry[i][j]);
			}
		}
		for (i=0, ok=true, ans=0; i<n&&ok; i++)
		{
			for (j=0; j<m&&ok; j++)
			{
				if (ary[i][j] != bry[i][j])
				{
					if (i+1<n && j+1<m)
					{
						t = bry[i][j]-ary[i][j];
						ans += abs(t);
						for (k=0; k<4; k++)
						{
							ary[i+dx[k]][j+dy[k]] += t;
						}
					}
					else
					{
						ok = false;
					}
				}
			}
		}
		puts(ok?"Yes":"No");
		if (ok)
		{
			printf("%lld\n", ans);
		}
	}
	return 0;
}
