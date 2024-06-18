#include <iostream>
using namespace std;

const int N = 200005;

char s[N];

int main()
{
	int i;
	scanf("%s", s);
	int cnt = 0;
	long long ans = 0;
	for (i=0; s[i]; i++)
	{
		if (s[i] == 'W')
		{
			ans += cnt;
		}
		else
		{
			++cnt;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
