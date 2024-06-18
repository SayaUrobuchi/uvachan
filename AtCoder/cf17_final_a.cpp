#include <iostream>
using namespace std;

const char *pat = "AKIHABARA";

char s[64];

int main()
{
	int i, j;
	scanf("%s", s);
	for (i=0, j=0; s[i]&&pat[j]; i++)
	{
		if (s[i] == pat[j])
		{
			j++;
		}
		else
		{
			if (pat[j] == 'A' && s[i] == pat[j+1])
			{
				j += 2;
			}
			else
			{
				break;
			}
		}
	}
	if (pat[j] == 'A')
	{
		++j;
	}
	if (!s[i] && !pat[j])
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	return 0;
}
