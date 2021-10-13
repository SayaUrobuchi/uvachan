#include <iostream>
#include <algorithm>
using namespace std;

int ucnt;
int n;
string str[256];
int last[256];
int qq[256], qs[256];
int used[256];
char b[2][256];

bool comp(const string &a, const string &b)
{
	return a.size() < b.size();
}

int diff(int a, int b)
{
	int i, c;
	for (i=0, c=0; i<str[a].size()&&c<2; i++)
	{
		if (str[a][i] != str[b][i])
		{
			c++;
		}
	}
	return c;
}

int bfs(string s, string t)
{
	int i, j, k, st, ed, cur;
	for (i=0; i<n; i++)
	{
		if (str[i] == s)
		{
			st = i;
		}
		if (str[i] == t)
		{
			ed = i;
		}
	}
	qq[0] = st;
	qs[0] = 0;
	++ucnt;
	for (i=0, j=1; i<j; i++)
	{
		cur = qq[i];
		if (cur == ed)
		{
			return qs[i];
		}
		for (k=last[s.size()]; k<n&&str[k].size()==s.size(); k++)
		{
			if (used[k] != ucnt && diff(cur, k) == 1)
			{
				used[k] = ucnt;
				qq[j] = k;
				qs[j] = qs[i] + 1;
				j++;
			}
		}
	}
	return -1;
}

int main()
{
	int count, i;
	string s;
	cin >> count;
	getline(cin, s);
	getline(cin, s);
	while (count--)
	{
		for (i=0; getline(cin, str[i])&&str[i]!="*"; i++);
		n = i;
		sort(str, str+n, comp);
		for (i=0; i<n; i++)
		{
			if (i == 0 || str[i].size() != str[i-1].size())
			{
				last[str[i].size()] = i;
			}
		}
		while (getline(cin, s) && s.size())
		{
			sscanf(s.c_str(), "%s%s", b[0], b[1]);
			printf("%s %s %d\n", b[0], b[1], bfs(b[0], b[1]));
		}
		if (count)
		{
			puts("");
		}
	}
	return 0;
}
