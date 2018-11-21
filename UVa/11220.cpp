#include <stdio.h>

char str[100000];

int main()
{
	int count, cas, i, n, len;
	cas = 0;
	scanf("%d", &count);
	gets(str);
	gets(str);
	while(count--)
	{
		printf("Case #%d:\n", ++cas);
		while(gets(str))
		{
			if(!str[0])
			{
				break;
			}
			for(i=0, n=1, len=0; str[i]; i++)
			{
				if(str[i] == 32)
				{
					len = 0;
				}
				else
				{
					len++;
					if(len == n)
					{
						printf("%c", str[i]);
						len = 0;
						n++;
						while(str[++i])
						{
							if(str[i] == 32)
							{
								break;
							}
						}
					}
				}
			}
			printf("\n");
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
