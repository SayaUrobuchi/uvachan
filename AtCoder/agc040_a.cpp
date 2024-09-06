#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 500005;

char s[N];

int main()
{
	int i, j;
	scanf("%s", s);
	int n = strlen(s);
	vector<int> que;
	vector< vector<int> > v(n+1);
	vector<int> deg(n+1), val(n+1);
	for (i=0; i<=n; i++)
	{
		if (i > 0)
		{
			if (s[i-1] == '>')
			{
				v[i].emplace_back(i-1);
			}
			else
			{
				++deg[i];
			}
		}
		if (i < n)
		{
			if (s[i] == '<')
			{
				v[i].emplace_back(i+1);
			}
			else
			{
				++deg[i];
			}
		}
		if (deg[i] == 0)
		{
			que.emplace_back(i);
		}
	}
	long long ans = 0;
	for (i=0; i<que.size(); i++)
	{
		int cur = que[i];
		ans += val[cur];
		for (j=0; j<v[cur].size(); j++)
		{
			int nxt = v[cur][j];
			val[nxt] = max(val[nxt], val[cur]+1);
			--deg[nxt];
			if (deg[nxt] == 0)
			{
				que.emplace_back(nxt);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
