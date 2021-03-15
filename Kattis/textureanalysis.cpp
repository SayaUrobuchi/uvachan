#include<iostream>
using namespace std;

char s[1048576];

int main()
{
	int cas, i, t, c, f;
	cas = 0;
	while (scanf("%s", s) == 1)
	{
		if (*s == 'E')
		{
			break;
		}
		for (i=0, t=0, c=0; s[i]; i++)
		{
			if (s[i] == '*')
			{
				if (c == 1)
				{
					f = t;
				}
				else if (c > 1)
				{
					if (f != t)
					{
						break;
					}
				}
				++c;
				t = 0;
			}
			else
			{
				++t;
			}
		}
		if (s[i])
		{
			printf("%d NOT EVEN\n", ++cas);
		}
		else
		{
			printf("%d EVEN\n", ++cas);
		}
	}
	return 0;
}
