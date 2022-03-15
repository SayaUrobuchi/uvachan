#include <iostream>
#include <cstring>
using namespace std;

int tbl[128];
char s[1048576];

int gcd(int a, int b)
{
	while ((a%=b) && (b%=a));
	return a+b;
}

int main()
{
	int n, i, j, t, ans;
	while (scanf("%s", s) == 1)
	{
		memset(tbl, 0, sizeof(tbl));
		for (n=0; s[n]; n++)
		{
			ans = ++tbl[s[n]];
		}
		for (i='a'; i<='z'&&ans>1; i++)
		{
			if (tbl[i])
			{
				ans = gcd(ans, tbl[i]);
			}
		}
		if (ans == 1)
		{
			puts("-1");
		}
		else
		{
			printf("%.*s\n", n/ans, s);
		}
	}
	return 0;
}
