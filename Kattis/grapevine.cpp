#include <iostream>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

const int N = 100005;
const int BS = 32;

int pre[N], hear[N];
char buf[BS], buf2[BS];
vector<int> v[N];

int main()
{
	int n, m, o, i, k;
	map<string, int> mp;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<n; i++)
	{
		scanf("%s%d", buf, &pre[i]);
		mp[buf] = i;
	}
	for (i=0; i<m; i++)
	{
		scanf("%s%s", buf, buf2);
		int a = mp[buf];
		int b = mp[buf2];
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	scanf("%s", buf);
	vector<pair<int, int> > que;
	que.emplace_back(mp[buf], 0);
	++hear[que[0].first];
	int ans = 0;
	for (i=0; i<que.size(); i++)
	{
		int id, day;
		tie(id, day) = que[i];
		if (day >= o)
		{
			break;
		}
		for (k=0; k<v[id].size(); k++)
		{
			int nxt = v[id][k];
			ans += (hear[nxt] == 0);
			if (++hear[nxt] == pre[nxt])
			{
				que.emplace_back(nxt, day+1);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
