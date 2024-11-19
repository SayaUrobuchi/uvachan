#include <iostream>
using namespace std;

const int N = 512;

int tim[N], st[N], intv[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=1; i<n; i++)
	{
		scanf("%d%d%d", &tim[i], &st[i], &intv[i]);
	}
	for (i=1; i<=n; i++)
	{
		int t = 0;
		for (j=i; j<n; j++)
		{
			t = max(t, st[j]);
			t += (intv[j] - t%intv[j]) % intv[j];
			t += tim[j];
		}
		printf("%d\n", t);
	}
	return 0;
}
