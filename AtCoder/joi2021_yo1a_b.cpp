#include <iostream>
using namespace std;

char s[128];
int cnt[128];

int main()
{
	int n, i, j;
	scanf("%d%s", &n, s);
	for (i=0; i<n; i++)
	{
		++cnt[s[i]];
	}
	const char *t = "JOI";
	for (i=0; i<3; i++)
	{
		for (j=0; j<cnt[t[i]]; j++)
		{
			putchar(t[i]);
		}
	}
	puts("");
	return 0;
}
