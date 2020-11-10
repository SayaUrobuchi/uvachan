#include <iostream>
#include <unordered_map>
using namespace std;

string key = "ACGT";
unordered_map<string, bool> tbl;

int search(string &s, string &t)
{
	int ans, i, j;
	if (tbl.find(s) != tbl.end())
	{
		return 0;
	}
	tbl[s] = true;
	for (i=0, ans=0; i+s.size()<=t.size(); i++)
	{
		for (j=0; j<s.size()&&s[j]==t[i+j]; j++);
		if (j >= s.size())
		{
			++ans;
		}
	}
	return ans;
}

int t2(string &s, string &t)
{
	int ans, i, j;
	string u;
	for (i=0, ans=0; i<4; i++)
	{
		u = s + key[i];
		ans += search(u, t);
		for (j=u.size()-1; j>0; j--)
		{
			swap(u[j], u[j-1]);
			ans += search(u, t);
		}
	}
	return ans;
}

int t1(string &s, string &t)
{
	int ans, i;
	string u = s;
	u.resize(s.size()-1);
	ans = search(u, t);
	for (i=u.size()-1; i>=0; i--)
	{
		u[i] = s[i+1];
		ans += search(u, t);
	}
	return ans;
}

int t0(string &s, string &t)
{
	return search(s, t);
}

int main()
{
	string s, t;
	while (cin >> s)
	{
		if (s == "0")
		{
			break;
		}
		tbl.clear();
		cin >> t;
		cout << t0(s, t) << " " << t1(s, t) << " " << t2(s, t) << "\n";
	}
	return 0;
}
