#include <iostream>
using namespace std;

char s[1048576];

int main()
{
	int i, b, k;
	scanf("%s", s);
	for (i=0, b=0, k=0; s[i]; i++)
	{
		if (s[i] == 'b')
		{
			++b;
		}
		else if (s[i] == 'k')
		{
			++k;
		}
	}
	if (b == 0 && k == 0)
	{
		puts("none");
	}
	else if (b > k)
	{
		puts("boba");
	}
	else if (k > b)
	{
		puts("kiki");
	}
	else
	{
		puts("boki");
	}
	return 0;
}
