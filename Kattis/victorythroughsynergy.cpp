#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 10;
const int SLEN = 16;

int syn[N], nod[N], deg[N];
int score[N][N];
char nam[N][SLEN], nation[N][SLEN], league[N][SLEN], team[N][SLEN];
bool used[N];
vector<int> edg[N];

bool dfs(int depth)
{
	int i, j;
	if (depth == N)
	{
		for (i=0; i<N; i++)
		{
			if (syn[nod[i]] < deg[i])
			{
				return false;
			}
		}
		return true;
	}
	for (i=0; i<N; i++)
	{
		if (!used[i])
		{
			nod[depth] = i;
			used[i] = true;
			for (j=0; j<edg[depth].size(); j++)
			{
				int nxt = nod[ edg[depth][j] ];
				syn[i] += score[i][nxt];
				syn[nxt] += score[nxt][i];
			}
			if (dfs(depth+1))
			{
				return true;
			}
			used[i] = false;
			for (j=0; j<edg[depth].size(); j++)
			{
				int nxt = nod[ edg[depth][j] ];
				syn[i] -= score[i][nxt];
				syn[nxt] -= score[nxt][i];
			}
		}
	}
	return false;
}

int main()
{
	int m, i, j, t, u, v;
	scanf("%d", &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &u, &v);
		if (u > v)
		{
			swap(u, v);
		}
		edg[v].emplace_back(u);
		++deg[v];
		++deg[u];
	}
	for (i=0; i<N; i++)
	{
		scanf("%s%s%s%s", nam[i], nation[i], league[i], team[i]);
		for (j=0; j<i; j++)
		{
			t = 0;
			if (strcmp(nation[i], nation[j]) == 0)
			{
				++t;
			}
			if (strcmp(team[i], team[j]) == 0)
			{
				t += 2;
			}
			else if (strcmp(league[i], league[j]) == 0)
			{
				++t;
			}
			score[i][j] = score[j][i] = t;
		}
	}
	bool is_ans = dfs(0);
	if (is_ans)
	{
		puts("yes");
	}
	else
	{
		puts("no");
	}
	return 0;
}