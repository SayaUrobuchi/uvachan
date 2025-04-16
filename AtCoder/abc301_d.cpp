#include <iostream>
#include <algorithm>
using namespace std;

const int N = 128;

char buf[N];

int main()
{
	long long n;
	int i;
	scanf("%s%lld", buf, &n);
	string s = buf;
	reverse(s.begin(), s.end());
	long long orig = 0;
	for (i=(int)s.size()-1; i>=0; i--)
	{
		if (s[i] == '1')
		{
			orig |= (1LL << i);
		}
	}
	long long ans = -1;
	if (orig <= n)
	{
		ans = orig;
		for (i=(int)s.size()-1; i>=0; i--)
		{
			if (s[i] == '?')
			{
				if (ans + (1LL << i) <= n)
				{
					ans += (1LL << i);
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
