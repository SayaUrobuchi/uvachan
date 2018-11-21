#include <stdio.h>
#include <string.h>

char s[1005];

int recurs(int p, int q)
{
	if(p >= q)
	{
		return 1;
	}
	if(s[p] == s[q])
	{
		return recurs(p+1, q-1);
	}
	return 0;
}

int main()
{
	while(scanf("%s", s) == 1)
	{
		printf("%s\n", recurs(0, strlen(s)-1)?"yes":"no");
	}
	return 0;
}
