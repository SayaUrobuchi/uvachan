#include<iostream>
using namespace std;

const long long M = 2147483647;

long long vv0[2048], vv1[2048];
int aa[2048], bb[2048], used[2048];
int ucnt, an, bn;

int main()
{
	int n, m, i, j, t, x, y;
	int *ary, *bry;
	long long *v0, *v1;
	long long ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		ary = aa;
		bry = bb;
		v0 = vv0;
		v1 = vv1;
		an = 1;
		ary[0] = m;
		v0[m] = 1;
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			++ucnt;
			for (j=0, bn=0; j<an; j++)
			{
				x = ary[j];
				y = m;
				if (x > y)
				{
					swap(x, y);
				}
				if (t > x)
				{
					if (used[x] != ucnt)
					{
						v1[x] = 0;
						bry[bn++] = x;
						used[x] = ucnt;
					}
					v1[x] += v0[ary[j]];
					v1[x] %= M;
				}
				if (t < y)
				{
					if (used[y] != ucnt)
					{
						v1[y] = 0;
						bry[bn++] = y;
						used[y] = ucnt;
					}
					v1[y] += v0[ary[j]];
					v1[y] %= M;
				}
			}
			m = t;
			swap(an, bn);
			swap(ary, bry);
			swap(v0, v1);
		}
		ans = 0;
		for (j=0; j<an; j++)
		{
			ans = (ans+v0[ary[j]]) % M;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
