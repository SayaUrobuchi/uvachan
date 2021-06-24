#include <iostream>
#include <vector>
using namespace std;

char s[1024];
vector<pair<int, int> > v0, v1;

int main()
{
	int n, i, j, t, d, best;
	while (scanf("%d", &n) == 1)
	{
		v0.clear();
		v1.clear();
		for (i=0; i<n; i++)
		{
			scanf("%s", s);
			for (j=0; j<n; j++)
			{
				if (s[j] == 'S')
				{
					v0.emplace_back(i, j);
				}
				else if (s[j] == 'H')
				{
					v1.emplace_back(i, j);
				}
			}
		}
		for (i=0, best=0; i<v0.size(); i++)
		{
			for (j=0, t=n*n; j<v1.size()&&t>best; j++)
			{
				d = abs(v0[i].first-v1[j].first) + abs(v0[i].second-v1[j].second);
				if (d < t)
				{
					t = d;
				}
			}
			if (t > best)
			{
				best = t;
			}
		}
		printf("%d\n", best);
	}
	return 0;
}
