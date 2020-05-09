#include <iostream>
#include <algorithm>
using namespace std;

int dp[200005][4];

int main()
{
	int count, i;
	string s, t;
	cin >> count;
	while (count--)
	{
		cin >> s;
		t = s;
		s += '\a';
		reverse(t.begin(), t.end());
		t += '\a';
		dp[0][0] = 1;
		for (i=0; i<t.size(); i++)
		{
			dp[i+1][0] = dp[i][0];
			if (s[i] != t[i])
			{
				dp[i+1][0] = 0;
			}
			dp[i+1][1] = 0;
			if ((dp[i][1] || dp[i][0]) && s[i+1] == t[i])
			{
				dp[i+1][1] = 1;
			}
			dp[i+1][2] = 0;
			if ((dp[i][2] || dp[i][0]) && s[i] == t[i+1])
			{
				dp[i+1][2] = 1;
			}
			dp[i+1][3] = 0;
			if (i > 0 && (dp[i-1][1] || dp[i-1][2] || dp[i-1][0] || dp[i][3]) && s[i] == t[i])
			{
				dp[i+1][3] = 1;
			}
		}
		if (dp[t.size()][3])
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}
