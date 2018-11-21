#include <stdio.h>
#include <string.h>

int tbl[128];
char s[100005];

int main()
{
	int i, res;
	for(i='a'; i<='z'; i++)
	{
		tbl[i] = i-'a'+1;
	}
	for(i='A'; i<='Z'; i++)
	{
		tbl[i] = i-'A'+1;
	}
	while(scanf("%s", s) == 1)
	{
		if(strcmp(s, "0") == 0)
		{
			break;
		}
		for(i=0, res=0; s[i]; i++)
		{
			if(tbl[s[i]] == 0)
			{
				break;
			}
			res += tbl[s[i]];
		}
		if(s[i])
		{
			printf("Fail\n");
		}
		else
		{
			printf("%d\n", res);
		}
	}
	return 0;
}
