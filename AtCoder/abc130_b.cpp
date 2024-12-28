#include <iostream>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	int cur = 0;
	for (i=0; i<n&&cur<=m; cur+=ary[i], i++);
	if (cur <= m)
	{
		++i;
	}
	printf("%d\n", i);
	return 0;
}
