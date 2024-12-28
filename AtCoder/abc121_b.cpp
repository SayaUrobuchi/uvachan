#include <iostream>
using namespace std;

const int N = 32;

int bry[N];

int main()
{
	int n, m, o, i, j;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<m; i++)
	{
		scanf("%d", &bry[i]);
	}
	int ans = 0;
	for (i=0; i<n; i++)
	{
		int res = o;
		for (j=0; j<m; j++)
		{
			int t;
			scanf("%d", &t);
			res += t * bry[j];
		}
		ans += (res > 0);
	}
	printf("%d\n", ans);
	return 0;
}
