#include <stdio.h>
#include <string.h>

char s[10005];

int main()
{
	int i, t;
	while(gets(s))
	{
		if(strcmp(s, "0") == 0)
		{
			break;
		}
		for(i=0, t=0; s[i]; i++)
		{
			t = (t*10+s[i]-'0')%17;
		}
		printf("%d\n", !t);
	}
	return 0;
}
