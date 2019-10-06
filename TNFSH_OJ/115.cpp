#include <stdio.h>
#include <string.h>

char str[16][1024], buf[1024];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=1; i<=10; i++)
	{
		strcpy(str[i], "EMPTY");
	}
	for (i=0; i<n; i++)
	{
		scanf("%s%d", buf, &j);
		strcpy(str[j], buf);
	}
	for (i=1; i<=10; i++)
	{
		puts(str[i]);
	}
	return 0;
}
