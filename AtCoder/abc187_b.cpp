#include <iostream>
using namespace std;

const int N = 1024;

int px[N], py[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	int ans = 0;
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &px[i], &py[i]);
		for (j=0; j<i; j++)
		{
			int dx = px[i] - px[j];
			int dy = py[i] - py[j];
			ans += (abs(dy) <= abs(dx));
		}
	}
	printf("%d\n", ans);
	return 0;
}
