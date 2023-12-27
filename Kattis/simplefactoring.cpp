#include <iostream>
using namespace std;

int main()
{
	int count, a, b, c, d, e, f, g;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &a, &b, &c);
		bool ans = false;
		for (d=1; d*d<=a&&!ans; d++)
		{
			if (a % d == 0)
			{
				f = a / d;
				for (e=1; e*e<=c&&!ans; e++)
				{
					if (c % e == 0)
					{
						g = c / e;
						if ((long long)e*f + (long long)d*g == b)
						{
							ans = true;
						}
						else if ((long long)g*f + (long long)d*e == b)
						{
							ans = true;
						}
					}
				}
			}
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}
