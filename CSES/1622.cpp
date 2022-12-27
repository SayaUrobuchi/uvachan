#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int used[16];
string res;
vector<string> v;

void dfs(string &s, int depth)
{
	int i, last;
	if (depth == s.size())
	{
		v.emplace_back(res);
		return;
	}
	for (i=0, last=0; i<s.size(); i++)
	{
		if (s[i] != last && !used[i])
		{
			used[i] = true;
			last = s[i];
			res[depth] = s[i];
			dfs(s, depth+1);
			used[i] = false;
		}
	}
}

int main()
{
	int i;
	string s;
	while (cin >> s)
	{
		sort(s.begin(), s.end());
		res.resize(s.size());
		v.clear();
		dfs(s, 0);
		cout << v.size() << "\n";
		for (i=0; i<v.size(); i++)
		{
			cout << v[i] << "\n";
		}
	}
	return 0;
}

