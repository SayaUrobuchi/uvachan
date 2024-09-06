#include <iostream>
using namespace std;

const int N = 16;

char s0[N], s1[N];

int main()
{
	int n;
	int l = 1;
	int r = 10;
	bool honest = true;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		scanf("%s%s", s0, s1);
		if (*s0 == 'r')
		{
			if (n >= l && n <= r && honest)
			{
				puts("Stan may be honest");
			}
			else
			{
				puts("Stan is dishonest");
			}
			l = 1;
			r = 10;
			honest = true;
		}
		else
		{
			if (*s1 == 'h')
			{
				if (n <= l)
				{
					honest = false;
				}
				else
				{
					r = min(r, n-1);
				}
			}
			else
			{
				if (n >= r)
				{
					honest = false;
				}
				else
				{
					l = max(l, n+1);
				}
			}
		}
	}
	return 0;
}
