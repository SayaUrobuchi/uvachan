#include <iostream>
using namespace std;

int mother[128];
const char *key = "aeiouy";

int main()
{
	int i, st, ed;
	string s;
	for (i=0; key[i]; i++)
	{
		mother[key[i]] = 1;
	}
	while (getline(cin, s))
	{
		for (i=0, st=ed=-1; i<=s.size(); i++)
		{
			if (i == s.size() || !(s[i] >= 'a' && s[i] <= 'z'))
			{
				if (st != -1)
				{
					if (st == ed)
					{
						printf("%.*syay", i-st, s.c_str()+st);
					}
					else
					{
						printf("%.*s%.*say", i-ed, s.c_str()+ed, ed-st, s.c_str()+st);
					}
				}
				putchar(i<s.size()?s[i]:'\n');
				st = ed = -1;
			}
			else
			{
				if (st == -1)
				{
					st = i;
				}
				if (mother[s[i]] && ed == -1)
				{
					ed = i;
				}
			}
		}
	}
	return 0;
}
