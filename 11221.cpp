#include <stdio.h>
#include <math.h>

char buf[10001], str[10001];

int main()
{
	int cas, count, i, j, k, n, sq;
	cas = 0;
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		printf("Case #%d:\n", ++cas);
		gets(buf);
		for(i=0, n=0; buf[i]; i++)
		{
			if((buf[i] > 64 && buf[i] < 91) || (buf[i] > 96 && buf[i] < 123))
			{
				str[n++] = buf[i];
			}
		}
		sq = sqrt(n);
		if(sq * sq == n)
		{
			for(i=0, j=n-1; i<j; i++, j--)
			{
				if(str[i] != str[j])
				{
					break;
				}
			}
			if(i < j)
			{
				printf("No magic :(\n");
			}
			else
			{
				for(k=0; k+k<sq; k++)
				{
					for(i=k, j=n-1-k; i<sq; i+=sq, j-=sq)
					{
						if(str[i] != str[j])
						{
							break;
						}
					}
					if(i < sq)
					{
						break;
					}
				}
				if(k+k < sq)
				{
					printf("No magic :(\n");
				}
				else
				{
					printf("%d\n", sq);
				}
			}
		}
		else
		{
			printf("No magic :(\n");
		}
	}
	return 0;
}
