#include <iostream>
using namespace std;

const int N = 1005;

int conn[N][N];

int main()
{
	int n, i, j, k, ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf("%d", &conn[i][j]);
		}
	}
	for (i=0, ans=0; i<n; i++)
	{
		for (j=i+1; j<n; j++)
		{
			if (conn[i][j])
			{
				for (k=j+1; k<n; k++)
				{
					if (conn[i][k] && conn[k][j])
					{
						++ans;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
