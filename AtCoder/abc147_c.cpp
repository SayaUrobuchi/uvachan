#include <iostream>
#include <vector>
using namespace std;

const int N = 32;

bool ary[N];
vector<int> id[N], typ[N];

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		int t;
		scanf("%d", &t);
		for (j=0; j<t; j++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			id[i].emplace_back(a);
			typ[i].emplace_back(b);
		}
	}
	int best = 0;
	for (i=0; i<(1<<n); i++)
	{
		int c = 0;
		for (j=0; j<n; j++)
		{
			ary[j+1] = (i & (1<<j));
			c += ary[j+1];
		}
		if (c > best)
		{
			bool is_ok = true;
			for (j=1; j<=n&&is_ok; j++)
			{
				if (ary[j])
				{
					for (k=0; k<id[j].size()&&is_ok; k++)
					{
						int t = id[j][k];
						int u = typ[j][k];
						if (ary[t] != u)
						{
							is_ok = false;
						}
					}
				}
			}
			if (is_ok)
			{
				best = c;
			}
		}
	}
	printf("%d\n", best);
	return 0;
}