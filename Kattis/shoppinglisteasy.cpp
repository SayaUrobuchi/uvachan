#include<iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
using um = unordered_map<string, bool>;

int main()
{
	int n, m, i, j;
	char s[16];
	um a, b;
	vector<string> v;
	while (scanf("%d%d", &n, &m) == 2)
	{
		a.clear();
		b.clear();
		for (i=0; i<m; i++)
		{
			scanf("%s", &s);
			a[s] = true;
		}
		for (i=1; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				scanf("%s", &s);
				if (a.find(s) != a.end())
				{
					b[s] = true;
				}
			}
			swap(a, b);
			b.clear();
		}
		v.resize(a.size());
		i = 0;
		for (um::iterator it=a.begin(); it!=a.end(); ++it)
		{
			v[i++] = it->first;
		}
		sort(v.begin(), v.end());
		printf("%d\n", v.size());
		j = v.size();
		for (i=0; i<j; i++)
		{
			printf("%s\n", v[i].c_str());
		}
	}
	return 0;
}
