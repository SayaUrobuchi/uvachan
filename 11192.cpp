#include <stdio.h>
#include <string.h>

char str[101], *ptr;

int main()
{
	int n, i, j;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		scanf("%s", str);
		n = strlen(str) / n - 1;
		ptr = str;
		while(*ptr)
		{
			for(i=0, j=n; i<j; i++, j--)
			{
				ptr[i] ^= ptr[j] ^= ptr[i] ^= ptr[j];
			}
			ptr += n + 1;
		}
		printf("%s\n", str);
	}
	return 0;
}
