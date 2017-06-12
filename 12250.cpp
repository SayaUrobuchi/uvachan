#include <stdio.h>
#include <string.h>

const char *s[6]={"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};
const char *r[7]={"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN", "UNKNOWN"};
char buf[100005];

int main()
{
	int cas, i;
	cas = 0;
	while(gets(buf))
	{
		if(*buf == '#' && !buf[1])
		{
			break;
		}
		for(i=0; i<6; i++)
		{
			if(strcmp(buf, s[i]) == 0)
			{
				break;
			}
		}
		printf("Case %d: %s\n", ++cas, r[i]);
	}
	return 0;
}
