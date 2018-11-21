#include <stdio.h>
#include <string.h>

int len[10];
char find[10][90], replace[10][90];
char str[300];
char buf[300];

int scomp(char* s1, char* s2)
{
	int i;
	for(i=0; s2[i]; i++)
	{
		if(s1[i] != s2[i])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n, i, j;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		gets(str);
		for(i=0; i<n; i++)
		{
			gets(find[i]);
			gets(replace[i]);
			len[i] = strlen(find[i]);
		}
		gets(str);
		for(i=0; i<n; i++)
		{
			while(1)
			{
				for(j=0; str[j]; j++)
				{
					if(scomp(str+j, find[i]))
					{
						strcpy(buf, str+j+len[i]);
						str[j] = 0;
						strcat(str, replace[i]);
						strcat(str, buf);
						break;
					}
				}
				if(!str[j])
				{
					break;
				}
			}
		}
		printf("%s\n", str);
	}
	return 0;
}
