#include <iostream>
using namespace std;

int main()
{
	int n, m, i, j, ans;
	scanf("%d%d", &n, &m);
	for (i=0, ans=0; i<=n&&i<=m; i++)
	{
		for (j=0; j<=n&&i+j<=m; j++)
		{
			if (m-i-j <= n)
			{
				++ans;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}