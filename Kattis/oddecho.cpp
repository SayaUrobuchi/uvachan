#include <iostream>
using namespace std;

char s[128];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", &s);
		if (!(i & 1))
		{
			puts(s);
		}
	}
	return 0;
}