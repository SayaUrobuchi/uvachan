#include <stdio.h>
#include <string.h>

char s[1000005];

int main()
{
	int i, t, c, nxt, las;
	while(gets(s))
	{
		if(strcmp(s, "END") == 0)
		{
			break;
		}
		if(strcmp(s, "1") == 0)
		{
			printf("1\n");
			continue;
		}
		i = strlen(s);
		c = 1;
		do
		{
			las = i;
			for(t=0; !t||i>0; i/=10, t++);
			i = t;
			c++;
		}while(i != las);
		printf("%d\n", c);
	}
	return 0;
}
