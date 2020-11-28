#include <iostream>

char s[1024];

int main()
{
	int count, cas, i, a, b;
	long long c;
	bool gg;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%s", &cas, s);
		for (i=0, a=0, b=0, c=0, gg=false; s[i]; i++)
		{
			a = (a<<3) + s[i] - '0';
			b = (b*10) + s[i] - '0';
			c = (c<<4) + s[i] - '0';
			if (s[i] >= '8')
			{
				gg = true;
			}
		}
		printf("%d %d %d %lld\n", cas, gg?0:a, b, c);
	}
	return 0;
}
