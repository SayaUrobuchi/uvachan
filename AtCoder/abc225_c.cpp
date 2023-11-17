#include <iostream>
using namespace std;

int ary[8];

int main()
{
	int n, m, i, j, t;
	bool ans;
	scanf("%d%d", &n, &m);
	ans = true;
	for (i=0; i<m; i++)
	{
		scanf("%d", &ary[i]);
		--ary[i];
		if (i > 0)
		{
			if (ary[i] % 7 != ary[i-1] % 7 + 1 || ary[i] != ary[i-1] + 1)
			{
				ans = false;
			}
		}
	}
	for (i=1; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			scanf("%d", &t);
			--t;
			if (t != ary[j] + 7)
			{
				ans = false;
			}
			ary[j] = t;
		}
	}
	if (ans)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}
