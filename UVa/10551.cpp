#include <stdio.h>
#include <string.h>

char str[1001], str2[11], buf[11];

int main()
{
	int b, m, n, i, len;
	while(scanf("%d", &b) == 1)
	{
		if(!b)
		{
			break;
		}
		scanf("%s%s", str, str2);
		for(i=0, m=0; str2[i]; i++)
		{
			m *= b;
			m += str2[i] - 48;
		}
		for(i=0, n=0; str[i]; i++)
		{
			n *= b;
			n += str[i] - 48;
			n %= m;
		}
		for(i=0; n; i++)
		{
			buf[i] = n % b;
			n /= b;
		}
		if(!i)
		{
			printf("0");
		}
		else
		{
			for(i--; i>-1; i--)
			{
				printf("%d", buf[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
