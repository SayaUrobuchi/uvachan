#include <iostream>
using namespace std;

int ary[100005];

int main()
{
	int n, m, i, j, ans;
	long long t;
	bool zero;
	scanf("%d%d", &n, &m);
	zero = false;
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		zero |= !ary[i];
	}
	if (zero)
	{
		ans = n;
	}
	else
	{
		for (i=0, j=0, t=1, ans=0; i<n; i++)
		{
			for (; j<n&&t*ary[j]<=m; t*=ary[j], j++);
			ans = max(ans, j-i);
			if (i < j)
			{
				t /= ary[i];
			}
			else
			{
				++j;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}