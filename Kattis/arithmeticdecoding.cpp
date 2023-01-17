#include <iostream>
using namespace std;

const int M = 45;

char buf[64];

int main()
{
	int n, a, i;
	long long t, l, r, c;
	char *s;
	scanf("%d%d%s", &n, &a, buf);
	s = buf + 2;
	for (i=0, t=0; i<M; i++)
	{
		t = (t<<1) | (s[i] & 1);
	}
	l = 0;
	r = (1LL << M);
	for (i=0; i<n; i++)
	{
		c = l + (((r-l) * a) >> 3);
		if (t >= c)
		{
			putchar('B');
			l = c;
		}
		else
		{
			putchar('A');
			r = c;
		}
	}
	puts("");
	return 0;
}
