#include <iostream>
using namespace std;

const int N = 1048576;

int dp[N], pos[N], ary[N], from[N];

void recurs(int cur)
{
	if (from[cur] >= 0)
	{
		recurs(from[cur]);
	}
	cout << ary[cur] << "\n";
}

int main()
{
	int count, i, ans, idx;
	string s;
	cin >> count;
	getline(cin, s);
	getline(cin, s);
	while (count--)
	{
		ans = 1;
		dp[0] = -1e9;
		pos[0] = -1;
		for (i=0; getline(cin, s); i++)
		{
			if (s.empty())
			{
				break;
			}
			ary[i] = stol(s);
			idx = lower_bound(dp, dp+ans, ary[i]) - dp;
			dp[idx] = ary[i];
			pos[idx] = i;
			from[i] = pos[idx-1];
			ans += (ans == idx);
		}
		cout << "Max hits: " << ans-1 << "\n";
		recurs(pos[ans-1]);
		if (count)
		{
			cout << "\n";
		}
	}
	return 0;
}
