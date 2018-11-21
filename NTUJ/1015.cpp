#include <stdio.h>
#include <string.h>

char *s[2], op[100000];

int main()
{
	int cas, a, b;
	cas = 0;
	s[0] = "false";
	s[1] = "true";
	while(scanf("%d%s%d", &a, op, &b) == 3)
	{
		if(strcmp(op, "E") == 0)
		{
			break;
		}
		if(strcmp(op, ">") == 0)
		{
			printf("Case %d: %s\n", ++cas, s[a>b]);
		}
		if(strcmp(op, "<") == 0)
		{
			printf("Case %d: %s\n", ++cas, s[a<b]);
		}
		if(strcmp(op, ">=") == 0)
		{
			printf("Case %d: %s\n", ++cas, s[a>=b]);
		}
		if(strcmp(op, "<=") == 0)
		{
			printf("Case %d: %s\n", ++cas, s[a<=b]);
		}
		if(strcmp(op, "==") == 0)
		{
			printf("Case %d: %s\n", ++cas, s[a==b]);
		}
		if(strcmp(op, "!=") == 0)
		{
			printf("Case %d: %s\n", ++cas, s[a!=b]);
		}
	}
	return 0;
}
