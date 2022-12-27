#include <iostream>
using namespace std;

char s[100005], t[100005];

int calc(char a, char b)
{
	a -= 'a';
	b -= 'a';
	return (b-a+26) % 26;
}

int main()
{
	int i, diff;
	bool gg;
	scanf("%s%s", s, t);
	diff = calc(s[0], t[0]);
	for (i=1, gg=false; s[i]; i++)
	{
		if (calc(s[i], t[i]) != diff)
		{
			gg = true;
			break;
		}
	}
	if (gg)
	{
		puts("No");
	}
	else
	{
		puts("Yes");
	}
	return 0;
}