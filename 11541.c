#include <stdio.h>
#include <string.h>

char buf[100000], a[128][1000];

int isdig(int c)
{
	return c >= '0' && c <= '9';
}

int main()
{
	int cas, count, n, i, temp;
	char *ptr;
	cas = 0;
	for(i=0; i<=127; i++)
	{
		memset(a[i], i, sizeof(a[i]));
	}
	gets(buf);
	sscanf(buf, "%d", &count);
	while(count--)
	{
		printf("Case %d: ", ++cas);
		gets(buf);
		for(ptr=buf; *ptr; )
		{
			temp = *ptr;
			for(n=0, ptr++; *ptr&&isdig(*ptr); n*=10, n+=*ptr-'0', ptr++);
			printf("%.*s", n, a[temp]);
		}
		putchar('\n');
	}
	return 0;
}
