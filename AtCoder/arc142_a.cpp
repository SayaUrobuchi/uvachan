#include <iostream>
#include <algorithm>
using namespace std;

const int N = 16;

char buf[N];

int main()
{
	long long n;
	scanf("%lld%s", &n, buf);
	int ans = 0;
	long long s = stoll(buf);
	string t = buf;
	reverse(t.begin(), t.end());
	long long u = stoll(t);
	t = to_string(u);
	reverse(t.begin(), t.end());
	long long w = stoll(t);
	if (s == min(u, w))
	{
		long long v = s;
		for (; v<=n; v*=10, ans++);
		if (u != s)
		{
			v = u;
			for (; v<=n; v*=10, ans++);
		}
	}
	printf("%d\n", ans);
	return 0;
}