#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, i, t;
	vector<pair<int, int> > v;
	while (scanf("%d", &n) == 1)
	{
		v.clear();
		v.emplace_back(-1e9, 0);
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			while (v.back().first >= t)
			{
				v.pop_back();
			}
			printf(i?" %d":"%d", v.back().second);
			v.emplace_back(t, i+1);
		}
		puts("");
	}
	return 0;
}

