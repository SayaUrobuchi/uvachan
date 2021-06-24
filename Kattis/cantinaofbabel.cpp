#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using mm = unordered_map<string, int>;
using mit = mm::iterator;

int ans;
int ucnt, used[256];
mm lang;
vector<int> speak, stk, edg[256], rev[256];
unordered_set<int> sub[256];

int getid(string &s)
{
	int id;
	mit it = lang.find(s);
	if (it == lang.end())
	{
		id = lang.size();
		lang[s] = id;
	}
	else
	{
		id = it->second;
	}
	return id;
}

void dfs(int cur)
{
	int i, nxt;
	if (used[cur] == ucnt)
	{
		return;
	}
	used[cur] = ucnt;
	for (i=0; i<edg[cur].size(); i++)
	{
		nxt = edg[cur][i];
		if (used[nxt] != ucnt)
		{
			dfs(nxt);
		}
	}
	stk.emplace_back(cur);
}

void rdfs(int cur)
{
	int i, nxt;
	if (used[cur] == ucnt)
	{
		return;
	}
	used[cur] = ucnt;
	++ans;
	for (i=0; i<rev[cur].size(); i++)
	{
		nxt = rev[cur][i];
		if (used[nxt] != ucnt)
		{
			rdfs(nxt);
		}
	}
}

int main()
{
	int n, i, j, id, best;
	string s;
	while (cin >> n)
	{
		lang.clear();
		speak.resize(n);
		getline(cin, s);
		for (i=0; i<n; i++)
		{
			getline(cin, s);
			stringstream ss(s);
			ss >> s;
			ss >> s;
			id = getid(s);
			speak[i] = id;
			sub[i].clear();
			while (ss >> s)
			{
				id = getid(s);
				sub[i].insert(id);
			}
			edg[i].clear();
			rev[i].clear();
			for (j=0; j<i; j++)
			{
				if (speak[i] == speak[j] || sub[j].count(speak[i]))
				{
					edg[i].emplace_back(j);
					rev[j].emplace_back(i);
				}
				if (speak[j] == speak[i] || sub[i].count(speak[j]))
				{
					edg[j].emplace_back(i);
					rev[i].emplace_back(j);
				}
			}
		}
		++ucnt;
		stk.clear();
		for (i=0; i<n; i++)
		{
			if (used[i] != ucnt)
			{
				dfs(i);
			}
		}
		++ucnt;
		for (i=n-1, best=1; i>=0; i--)
		{
			if (used[stk[i]] != ucnt)
			{
				ans = 0;
				rdfs(stk[i]);
				if (ans > best)
				{
					best = ans;
				}
			}
		}
		printf("%d\n", n-best);
	}
	return 0;
}
