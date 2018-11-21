#include <stdio.h>

int tbl[128];
char buf[100000];

int main()
{
	int cas, count, ans, i, j;
	char *ptr;
	cas = 0;
	tbl[' '] = 1;
	for(i='a', j=1; i<='z'; i++, j++)
	{
		if(j > 3 && i != 's' && i != 'z')
		{
			j = 1;
		}
		tbl[i] = j;
	}
	gets(buf);
	sscanf(buf, "%d", &count);
	while(count--)
	{
		gets(buf);
		for(ans=0, ptr=buf; *ptr; ans+=tbl[*ptr], ptr++);
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}
