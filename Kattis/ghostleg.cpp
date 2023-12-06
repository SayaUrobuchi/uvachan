#include <iostream>
using namespace std;

int ary[128];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		ary[i] = i;
	}
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		swap(ary[t], ary[t+1]);
	}
	for (i=1; i<=n; i++)
	{
		printf("%d\n", ary[i]);
	}
	return 0;
}
