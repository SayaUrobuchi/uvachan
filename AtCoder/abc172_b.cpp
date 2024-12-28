#include <iostream>
using namespace std;

const int N = 200005;

char s[N], t[N];

int main()
{
	int i;
	scanf("%s%s", s, t);
	int ans = 0;
	for (i=0; s[i]; i++)
	{
		ans += (s[i] != t[i]);
	}
	printf("%d\n", ans);
	return 0;
}
