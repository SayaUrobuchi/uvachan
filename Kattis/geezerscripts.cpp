#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<int, pp>;

const int N = 100005;

int dis[N];
vector<ppp> conn[N];

int calc(int hp, int atk, int ehp, int eatk)
{
	int my_turn = (hp+eatk-1) / eatk;
	int en_turn = (ehp+atk-1) / atk;
	hp -= min(my_turn, en_turn-1) * eatk;
	return hp;
}

int main()
{
	int n, m, i, a, b, c, d, atk, hp, cur, nxt, eatk, ehp, remain;
	scanf("%d%d", &atk, &hp);
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		conn[a].emplace_back(b, make_pair(c, d));
	}
	priority_queue<pp> pq;
	pq.emplace(hp, 1);
	dis[1] = hp;
	while (pq.size())
	{
		tie(hp, cur) = pq.top();
		pq.pop();
		if (dis[cur] != hp)
		{
			continue;
		}
		if (cur == n)
		{
			break;
		}
		for (i=0; i<conn[cur].size(); i++)
		{
			forward_as_tuple(nxt, tie(eatk, ehp)) = conn[cur][i];
			remain = calc(hp, atk, ehp, eatk);
			if (remain > dis[nxt])
			{
				dis[nxt] = remain;
				pq.emplace(remain, nxt);
			}
		}
	}
	if (dis[n] <= 0)
	{
		puts("Oh no");
	}
	else
	{
		printf("%d\n", dis[n]);
	}
	return 0;
}
