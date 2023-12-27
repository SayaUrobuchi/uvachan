#include <iostream>
using namespace std;

const int N = 10005;

int px[N], py[N];

int main()
{
	int n, m, i, j, a, b, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%*d%*d%d%d", &a, &b);
			px[i] = a;
			py[i] = a + b;
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			b += a;
			for (j=0, ans=0; j<n; j++)
			{
				if (b > px[j] && py[j] > a)
				{
					++ans;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
