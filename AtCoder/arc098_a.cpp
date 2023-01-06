#include <iostream>
using namespace std;

const int N = 300005;

int west[N], east[N];
char s[N];

int main()
{
	int n, i, ans;
	scanf("%d%s", &n, s+1);
	for (i=1; s[i]; i++)
	{
		west[i] = west[i-1] + (s[i] == 'W');
		east[i] = east[i-1] + (s[i] == 'E');
	}
	east[n+1] = east[n];
	for (i=1, ans=1e9; i<=n; i++)
	{
		ans = min(ans, west[i-1] + (east[n]-east[i]));
	}
	printf("%d\n", ans);
	return 0;
}
