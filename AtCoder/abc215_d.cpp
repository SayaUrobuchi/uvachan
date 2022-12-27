#include <iostream>
#include <set>
using namespace std;

int tbl[100005], ary[100005];

int main()
{
	int n, m, i, j, k, p, t, ans;
	set<int> se;
	for (i=3; i*i<=100000; i+=2)
	{
		if (!tbl[i])
		{
			for (j=i*i, k=i+i; j<=100000; j+=k)
			{
				tbl[j] = i;
			}
		}
	}
	while (scanf("%d%d", &n, &m) == 2)
	{
		se.clear();
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			while (t > 1)
			{
				p = tbl[t];
				if (!p)
				{
					if (t & 1)
					{
						p = t;
					}
					else
					{
						p = 2;
					}
				}
				se.insert(p);
				while (t%p == 0)
				{
					t /= p;
				}
			}
		}
		for (i=2; i<=m; i++)
		{
			ary[i] = false;
		}
		ans = 0;
		for (auto it=se.begin(); it!=se.end(); ++it)
		{
			for (i=*it; i<=m; i+=*it)
			{
				if (!ary[i])
				{
					ary[i] = true;
					++ans;
				}
			}
		}
		printf("%d\n", m-ans);
		for (i=1; i<=m; i++)
		{
			if (!ary[i])
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}

