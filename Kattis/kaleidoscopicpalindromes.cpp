#include <iostream>
using namespace std;

int ary[128];

int main()
{
	int m, a, b, i, j, k, t, p, q, ans;
	scanf("%d%d%d", &a, &b, &m);
	for (i=a, ans=0; i<=b; i++)
	{
		bool ok = true;
		for (j=2; j<=m&&j<=i&&ok; j++)
		{
			for (t=i, k=0; t; t/=j, k++)
			{
				ary[k] = t % j;
			}
			bool pal = true;
			for (p=0, q=k-1; p<q&&pal; p++, q--)
			{
				if (ary[p] != ary[q])
				{
					pal = false;
				}
			}
			if (!pal)
			{
				ok = false;
			}
		}
		ans += ok;
	}
	printf("%d\n", ans);
	return 0;
}
