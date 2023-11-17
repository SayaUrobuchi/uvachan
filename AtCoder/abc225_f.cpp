#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
string str[55], dp[55][2505];
char buf[55];

bool comp(const string &a, const string &b)
{
	return a+b < b+a;
}

string solve()
{
	int i, j, k, lim;
	string ans;
	bool used[55][2505] = {};
	used[0][0] = true;
	for (i=0, lim=0; i<n; lim+=str[i].size(), i++)
	{
		for (k=i+1; k>0; k--)
		{
			for (j=lim+str[i].size(); j>=str[i].size(); j--)
			{
				if (used[k-1][j-str[i].size()] && (!used[k][j] || dp[k][j] > dp[k-1][j-str[i].size()]+str[i]))
				{
					used[k][j] = true;
					dp[k][j] = dp[k-1][j-str[i].size()] + str[i];
				}
			}
		}
	}
	for (i=1, ans=""; i<=lim; i++)
	{
		if (used[m][i] && (ans.empty() || dp[m][i] < ans))
		{
			ans = dp[m][i];
		}
	}
	return ans;
}

int main()
{
	int i;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		str[i] = buf;
	}
	sort(str, str+n, comp);
	string ans = solve();
	puts(ans.c_str());
	return 0;
}
