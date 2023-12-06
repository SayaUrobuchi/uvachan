#include <iostream>
using namespace std;

char s[128];

int main()
{
	int a, b, c;
	fgets(s, sizeof(s), stdin);
	scanf("%d%d%d", &a, &b, &c);
	if (a >= b)
	{
		puts("VEIT EKKI");
	}
	else if (a-b == c)
	{
		puts("JEDI");
	}
	else
	{
		puts("SITH");
	}
	return 0;
}
