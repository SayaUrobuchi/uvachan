#include <iostream>
using namespace std;

char buf[1024], s[4][1024];

int main()
{
	int i;
	while (scanf("%s%s%s%s", s[0], s[1], s[2], buf) == 4)
	{
		for (i=0; buf[i]; i++)
		{
			printf("%s", s[buf[i]-'1']);
		}
		puts("");
	}
	return 0;
}

