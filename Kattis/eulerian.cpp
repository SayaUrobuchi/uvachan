#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;

int outd[N], ind[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		++outd[a];
		++ind[b];
	}
	vector<int> sted;
	bool is_ok = true;
	for (i=1; i<=n&&is_ok; i++)
	{
		if (outd[i] != ind[i])
		{
			if (abs(outd[i]-ind[i]) == 1)
			{
				sted.emplace_back(i);
				if (sted.size() > 2)
				{
					is_ok = false;
				}
			}
			else
			{
				is_ok = false;
			}
		}
	}
	if (!is_ok)
	{
		puts("no");
	}
	else
	{
		if (sted.empty())
		{
			puts("anywhere");
		}
		else
		{
			if (ind[sted[0]] > outd[sted[0]])
			{
				swap(sted[0], sted[1]);
			}
			printf("%d %d\n", sted[0], sted[1]);
		}
	}
	return 0;
}