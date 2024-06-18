#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	int a1;
	scanf("%d", &a1);
	int at = (1 << a1);
	int first = n, last = 0;
	for (i=1; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		at |= (1 << t);
		if (a1 != t)
		{
			first = min(first, i);
			last = max(last, i);
		}
	}
	int ans = 0;
	bool shifted = false;
	int bt = 0;
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		bt |= (1 << t);
		++ans;
		if (t != a1)
		{
			if (!shifted)
			{
				ans += min(first, n-last);
				shifted = true;
			}
			else
			{
				++ans;
			}
			a1 = t;
		}
	}
	if ((bt & at) != bt)
	{
		ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}
