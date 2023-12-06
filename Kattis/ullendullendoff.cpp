#include <iostream>
using namespace std;

char s[16];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", s);
		if (i == 12%n)
		{
			puts(s);
		}
	}
	return 0;
}
