#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;

const int M = 1000005;
const int N = 15;

int ary[N], bry[N];
bool used[M];

int main()
{
	int n, m, i, j, st;
	scanf("%d%d%d", &m, &n, &st);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &ary[i], &bry[i]);
	}
	vector<pp> que;
	used[st] = true;
	que.emplace_back(st, 0);
	int ans = -1;
	for (i=0; i<que.size(); i++)
	{
		int cur, d;
		tie(cur, d) = que[i];
		if (cur == 0)
		{
			ans = d;
			break;
		}
		for (j=0; j<n; j++)
		{
			int nxt = ((long long)cur * ary[j] + bry[j]) % m;
			if (!used[nxt])
			{
				used[nxt] = true;
				que.emplace_back(nxt, d+1);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
