#include <stdio.h>
#include <string.h>

char buf[1001];
char ans[1001];
char str[1001];

int recursion(char* s)
{
	int i;
	if(*s == '2' && s[1])
	{
		for(i=0; s[i]; i++)
		{
			if(s[i] == '0')
			{
				strcpy(ans, "NOT ACCEPTABLE");
				return 0;
			}
		}
		strcpy(ans, s+1);
		return 1;
	}
	else if(*s == '3' && s[1])
	{
		if(recursion(s+1))
		{
			strcpy(buf, ans);
			sprintf(ans, "%s2%s", buf, buf);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	strcpy(ans, "NOT ACCEPTABLE");
	return 0;
}

int main()
{
	while(gets(str))
	{
		if(str[0] == '0')
		{
			break;
		}
		recursion(str);
		printf("%s\n", ans);
	}
	return 0;
}
