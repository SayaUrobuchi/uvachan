#include <iostream>
#include <algorithm>
using namespace std;

int ary[128];

int main()
{
	int n, m, i, t;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	for (i=0, t=0; i<n&&t+ary[i]<=m; t+=ary[i], i++);
	if (i == n && t != m)
	{
		--i;
	}
	printf("%d\n", i);
	return 0;
}