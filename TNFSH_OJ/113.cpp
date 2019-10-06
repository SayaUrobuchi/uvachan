#include <stdio.h>

char buf[16], cmd[16];

int main()
{
	int n, pos;
	scanf("%d%s%s", &n, buf+1, cmd);
	buf[0] = '.';
	buf[n+1] = '.';
	if (*cmd == 'L')
	{
		pos = 1;
	}
	else
	{
		pos = -1;
	}
	printf("%.*s\n", n, buf+1+pos);
	return 0;
}
