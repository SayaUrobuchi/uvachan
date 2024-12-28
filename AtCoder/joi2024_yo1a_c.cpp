#include <iostream>
using namespace std;

const int N = 128;

char s[N], t[N];

int main()
{
	int n, i;
	scanf("%d%s%s", &n, s, t);
	int ans = 0;
	for (i=0; i<n; i++)
	{
		ans += (s[i] != t[i]);
	}
	printf("%d\n", ans);
	return 0;
}
