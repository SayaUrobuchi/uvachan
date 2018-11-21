#include <stdio.h>
#include <string.h>

char str[3005];

int main()
{
	int count, i, j, k, len;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", str);
		len = strlen(str);
		for(i=0; i<len; i++)
		{
			if((len-i) % 2 == 0)
			{
				j = (len-i)/2;
				if(strncmp(str+i, str+i+j, j) == 0)
				{
					break;
				}
			}
		}
		for(k=0; k<=8; k+=j)
		{
			printf("%.*s", j>8-k?8-k:j, str+i);
		}
		printf("...\n");
	}
	return 0;
}
