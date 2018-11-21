#include <stdio.h>

char s[10000000];

void recurs(int n, char *s)
{
	int i;
	if(n < 2)
	{
		*s = '0';
		*(s+1) = 0;
		return;
	}
	for(i=0; n>0; i++)
	{
		s[i] = (n&1)+'0';
		n >>= 1;
	}
	recurs(i-1, s+i);
}

int main()
{
	int n, i;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		recurs(n, s);
		for(i=0; s[i]; i++);
		for(i--; i>=0; i--)
		{
			printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}
