#include <iostream>
using namespace std;

int ary[2048], bry[2048];

int main()
{
	int n, i, j, a, b, t, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d%d%d", &t, &a, &b);
			--t;
			a <<= 1;
			b <<= 1;
			if (t & 1)
			{
				--b;
			}
			if (t & 2)
			{
				++a;
			}
			ary[i] = a;
			bry[i] = b;
			for (j=0; j<i; j++)
			{
				if (bry[i] >= ary[j] && bry[j] >= ary[i])
				{
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
