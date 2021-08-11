#include <iostream>

const char *key = "0125986";

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (; n>0; n/=7)
		{
			printf("%c", key[n%7]);
		}
		puts("");
	}
	return 0;
}
