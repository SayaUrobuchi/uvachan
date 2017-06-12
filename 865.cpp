#include <stdio.h>

char buf[200], tbl[128], crypt[128], plain[128];

int main()
{
	int count, i;
	char *ptr;
	scanf("%d", &count);
	gets(buf);
	gets(buf);
	while(count--)
	{
		for(i=0; i<128; i++)
		{
			tbl[i] = i;
		}
		gets(plain);
		gets(crypt);
		for(i=0; crypt[i]; i++)
		{
			tbl[plain[i]] = crypt[i];
		}
		puts(crypt);
		puts(plain);
		while(gets(buf))
		{
			if(buf[0] == 0)
			{
				break;
			}
			for(ptr=buf; *ptr; *ptr=tbl[*ptr], ptr++);
			puts(buf);
		}
		if(count)
		{
			puts("");
		}
	}
	return 0;
}
