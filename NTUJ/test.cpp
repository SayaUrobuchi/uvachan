#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[1000005];

int main()
{
	int v, k, i;
	char *ptr, *pp;
	while(gets(s))
	{
		sscanf(s, "%*d%d", &k);
		pp = strstr(s, ")");
		*pp = 0;
		/*ptr = strstr(s, "(");
		ptr = strtok(ptr, "(,");
		i = 0;
		do
		{
			sscanf(ptr, "%d", &v);
			i++;
		}while(ptr=strtok(NULL, "(,"));
		while(i!=k);*/
		ptr = pp+1;
		ptr = strtok(ptr, " ");
		do
		{
			sscanf(ptr, "%d", &v);
			while(v > k);
		}while(ptr=strtok(NULL, " "));
		gets(s);
	}
	return 0;
}
