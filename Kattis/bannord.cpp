#include <iostream>
using namespace std;

bool tbl[128];
char s[100005];

int main()
{
	int i;
	scanf("%s", s);
	for (i=0; s[i]; ++i)
	{
		tbl[s[i]] = true;
	}
	bool first = true;
	while (scanf("%s", s) == 1)
	{
		bool hide = false;
		for (i=0; !hide&&s[i]; ++i)
		{
			if (tbl[s[i]])
			{
				hide = true;
			}
		}
		if (hide)
		{
			for (i=0; s[i]; ++i)
			{
				s[i] = '*';
			}
		}
		if (!first)
		{
			putchar(' ');
		}
		printf("%s", s);
		first = false;
	}
	puts("");
	return 0;
}
