#include <iostream>
using namespace std;

const int N = 200005;

char s[N<<1];

int main()
{
	int n, m, i;
	scanf("%d%s%d", &n, s, &m);
	int n2 = (n << 1);
	int k = 0;
	for (i=0; i<m; i++)
	{
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		if (t == 1)
		{
			swap(s[(a-1+n*k)%n2], s[(b-1+n*k)%n2]);
		}
		else
		{
			k = 1 - k;
		}
	}
	for (i=0; i<n2; i++)
	{
		putchar(s[(i+n*k)%n2]);
	}
	puts("");
	return 0;
}
