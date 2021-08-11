#include <iostream>
#include <cmath>
using namespace std;

char buf[1024];

bool equal(double a, double b)
{
	return fabs(a-b) < 1e-7;
}

int main()
{
	int n, i;
	bool gg;
	while (scanf("%s", buf) == 1)
	{
		if (*buf == 'E')
		{
			break;
		}
		if (sscanf(buf, "%*d.%d", &n) != 1)
		{
			puts("MEMBER");
			continue;
		}
		for (i=0, gg=false; i<100; i++)
		{
			n *= 3;
			if (n >= 1000000 && n < 2000000)
			{
				gg = true;
				break;
			}
			n %= 1000000;
		}
		if (gg)
		{
			puts("NON-MEMBER");
		}
		else
		{
			puts("MEMBER");
		}
	}
	return 0;
}
