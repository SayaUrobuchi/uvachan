#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;

int cnt[N];
vector<int> v[N];
bool used[N];

int main()
{
	int n, m, o, i, j, a, b, st;
	scanf("%d%d%d%d", &n, &m, &o, &st);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	vector<int> que;
	que.emplace_back(st);
	used[st] = true;
	for (i=0; i<que.size(); i++)
	{
		int cur = que[i];
		for (j=0; j<v[cur].size(); j++)
		{
			int tar = v[cur][j];
			++cnt[tar];
			if (!used[tar] && (cnt[tar]<<1) >= v[tar].size())
			{
				used[tar] = true;
				que.emplace_back(tar);
			}
		}
	}
	puts(used[o]?"leave":"stay");
	return 0;
}
