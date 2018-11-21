#include <stdio.h>
#include <string.h>

int num[30];
int list[30][10];
int assigned[30];
int cused[10], aused[30];
int c[30];
char str[1000];

int fill(int);

int assign(int now)
{
	if(!assigned[now])
	{
		return 1;
	}
	else if(!aused[assigned[now]])
	{
		return fill(assigned[now]);
	}
	return 0;
}

int fill(int now)
{
	int i;
	aused[now] = 1;
	for(i=0; i<num[now]; i++)
	{
		if(!cused[list[now][i]])
		{
			cused[list[now][i]] = 1;
			if(assign(list[now][i]))
			{
				assigned[list[now][i]] = now;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i, j, now;
	while(gets(str))
	{
		memset(num, 0, sizeof(num));
		memset(c, 0, sizeof(c));
		do
		{
			if(!str[0])
			{
				break;
			}
			now = str[0] - 64;
			c[now] = str[1] - 48;
			for(i=3; str[i]!=';'; i++)
			{
				list[now][num[now]++] = str[i] - 48;
			}
		}while(gets(str));
		memset(assigned, 0, sizeof(assigned));
		for(i=1; i<=26; i++)
		{
			for(; c[i]; c[i]--)
			{
				memset(cused, 0, sizeof(cused));
				memset(aused, 0, sizeof(aused));
				if(!fill(i))
				{
					break;
				}
			}
			if(c[i])
			{
				break;
			}
		}
		if(i > 26)
		{
			for(i=0; i<10; i++)
			{
				if(assigned[i])
				{
					printf("%c", assigned[i]+64);
				}
				else
				{
					printf("_");
				}
			}
			printf("\n");
		}
		else
		{
			printf("!\n");
		}
	}
	return 0;
}
