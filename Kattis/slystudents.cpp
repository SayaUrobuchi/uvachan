#include <iostream>
using namespace std;

char buf[1048576];

int gcd(int a, int b)
{
	while ((a %= b) && (b %= a));
	return a + b;
}

void p3b(int t)
{
	if (t >= 3)
	{
		p3b(t/3);
	}
	putchar('0'+t%3);
}

int main()
{
	int i, g;
	while (scanf("%s", buf) == 1)
	{
		for (i=1, g=buf[0]; buf[i]; i++)
		{
			g = gcd(g, buf[i]);
		}
		printf("%d\n", g);
		for (i=0; buf[i]; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			p3b(buf[i]/g);
		}
		puts("");
	}
	return 0;
}
