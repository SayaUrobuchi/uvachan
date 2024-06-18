#include <iostream>
using namespace std;

const int N = 10005;
const int SN = (1 << 10);
const int M = 998244353;

int cnt[2][N][SN], dp[2][N][SN], ten[N];
bool used[2][N][SN];

int rec(bool zero, int n, int st)
{
	if (used[zero][n][st])
	{
		return dp[zero][n][st];
	}
	used[zero][n][st] = true;
	if (n == 0)
	{
		cnt[zero][n][st] = !st;
		dp[zero][n][st] = 0;
		return 0;
	}
	int ret = 0;
	int i;
	for (i=0; i<=9; i++)
	{
		int nn = n - 1;
		int ns = (st & ~(1 << i));
		int nz = (zero && !i);
		if (nz)
		{
			ns = st;
		}
		rec(nz, nn, ns);
		cnt[zero][n][st] = (cnt[zero][n][st] + cnt[nz][nn][ns]) % M;
		ret = (((ret + dp[nz][nn][ns]) % M) + 
			(((i * 1LL * cnt[nz][nn][ns]) % M) * ten[n-1]) % M) % M;
	}
	dp[zero][n][st] = ret;
	return ret;
}

int main()
{
	int n, i, j, st;
	string s;
	cin >> s;
	ten[0] = 1;
	for (i=1; i<s.size(); i++)
	{
		ten[i] = (ten[i-1] * 10LL) % M;
	}
	cin >> n;
	st = 0;
	for (i=0; i<n; i++)
	{
		int t;
		cin >> t;
		st |= (1 << t);
	}
	int stat = st;
	int ans = 0;
	int len = s.size();
	int cur = 0;
	bool zero = true;
	for (i=0; i<len; i++)
	{
		for (j=0; j+'0'<s[i]; j++)
		{
			int ss = stat & ~(1<<j);
			int nn = len-i-1;
			int tt = (cur + (j * 1LL * ten[nn]) % M) % M;
			int zz = (zero && !j);
			if (zz)
			{
				ss = stat;
			}
			rec(zz, nn, ss);
			ans = ((ans + dp[zz][nn][ss]) % M + (cnt[zz][nn][ss] * 1LL * tt) % M) % M;
			//cout << ans << "\n";
		}
		cur = (cur + ((s[i] - '0') * 1LL * ten[len-i-1]) % M) % M;
		if (zero && s[i] != '0')
		{
			zero = false;
		}
		if (!zero)
		{
			stat = (stat & ~(1<<(s[i]-'0')));
		}
	}
	if (stat == 0)
	{
		ans = (ans + cur) % M;
	}
	cout << ans << "\n";
	return 0;
}