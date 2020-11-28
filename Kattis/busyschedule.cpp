#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, i;
	bool first;
	vector<pair<string, pair<int, int> > > v;
	char buf[1024];
	first = true;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		v.resize(n);
		for (i=0; i<n; i++)
		{
			scanf("%d:%d%s", &v[i].second.first, &v[i].second.second, buf);
			v[i].second.first %= 12;
			v[i].first = buf;
		}
		sort(v.begin(), v.end());
		if (!first)
		{
			puts("");
		}
		first = false;
		for (i=0; i<n; i++)
		{
			if (v[i].second.first == 0)
			{
				v[i].second.first = 12;
			}
			printf("%d:%02d %s\n", v[i].second.first, v[i].second.second, v[i].first.c_str());
		}
	}
	return 0;
}
