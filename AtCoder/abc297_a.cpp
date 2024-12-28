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
	int ans = -1;
	for (i=1; i<n; i++)
	{
		if (ary[i] - ary[i-1] <= m)
		{
			ans = ary[i];
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
