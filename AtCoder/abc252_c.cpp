#include <iostream>
using namespace std;

const int N = 105;
const int M = 15;

int pos[N][M], last[M];
char buf[M];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		for (j=0; j<10; j++)
		{
			pos[i][buf[j]-'0'] = j;
		}
	}
	int ans = n * 20;
	for (i=0; i<10; i++)
	{
		for (j=0; j<10; j++)
		{
			last[j] = j - 10;
		}
		int res = 0;
		for (j=0; j<n; j++)
		{
			last[pos[j][i]] += 10;
			res = max(res, last[pos[j][i]]);
		}
		ans = min(ans, res);
	}
	printf("%d\n", ans);
	return 0;
}
