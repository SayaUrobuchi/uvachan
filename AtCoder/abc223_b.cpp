#include <iostream>
#include <cstring>
using namespace std;

char s[1024];

int main()
{
	int n, i, a, b;
	scanf("%s", s);
	n = strlen(s);
	strncpy(s+n, s, n);
	s[n+n] = 0;
	for (i=0, a=0, b=0; i<n; i++)
	{
		if (strncmp(s+a, s+i, n) > 0)
		{
			a = i;
		}
		if (strncmp(s+b, s+i, n) < 0)
		{
			b = i;
		}
	}
	printf("%.*s\n%.*s\n", n, s+a, n, s+b);
	return 0;
}
