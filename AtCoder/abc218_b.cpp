#include <iostream>
using namespace std;

char s[128];

int main()
{
	int i, t;
	while (scanf("%d", &t) == 1)
	{
		s[0] = 'a' + t - 1;
		for (i=1; i<26; i++)
		{
			scanf("%d", &t);
			s[i] = 'a' + t - 1;
		}
		s[i] = 0;
		puts(s);
	}
	return 0;
}

