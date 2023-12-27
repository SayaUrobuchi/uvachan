#include <iostream>
using namespace std;

const int N = 128;

char buf[N][N];

int main()
{
	int count, n, m, i, j, k, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%s", &n, &m, buf[0]);
		for (i=1, ans=n; i<m; i++)
		{
			scanf("%s", buf[i]);
			for (j=0; j<n; j++)
			{
				bool fit = true;
				for (k=0; j+k<n&&fit; k++)
				{
					if (buf[i-1][j+k] != buf[i][k])
					{
						fit = false;
					}
				}
				if (fit)
				{
					break;
				}
			}
			ans += j;
		}
		printf("%d\n", ans);
	}
	return 0;
}
