#include <stdio.h>
#include <string.h>

int n, m;
int tbl[26], sum[26];
int list[2000];
char dic[2000][21];
char ary[2000][21];
char str[1000];
char s[1000];
char *ptr;

int dfs(int last, int depth)
{
	int i, j, temp[26];
	if(!memcmp(tbl, sum, sizeof(tbl)))
	{
		printf("%s =", str);
		for(i=0; i<depth; i++)
		{
			printf(" %s", dic[list[i]]);
		}
		printf("\n");
		return 0;
	}
	for(i=last; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			if(!strcmp(dic[i], ary[j]))
			{
				break;
			}
		}
		if(j == m)
		{
			list[depth] = i;
			memcpy(temp, tbl, sizeof(temp));
			for(j=0, ptr=dic[i]; ptr[j]; j++)
			{
				tbl[ptr[j]-65]++;
				if(tbl[ptr[j]-65] > sum[ptr[j]-65])
				{
					break;
				}
			}
			if(!ptr[j])
			{
				dfs(i+1, depth+1);
			}
			memcpy(tbl, temp, sizeof(temp));
		}
	}
	return 0;
}

int main()
{
	int i;
	while(gets(dic[n]))
	{
		if(dic[n][0] == '#')
		{
			break;
		}
		n++;
	}
	while(gets(str))
	{
		if(str[0] == '#')
		{
			break;
		}
		memset(tbl, 0, sizeof(tbl));
		memset(sum, 0, sizeof(sum));
		strcpy(s, str);
		ptr = strtok(s, " ");
		m = 0;
		do
		{
			strcpy(ary[m++], ptr);
			for(i=0; ptr[i]; i++)
			{
				sum[ptr[i]-65]++;
			}
		}while(ptr=strtok(NULL, " "));
		dfs(0, 0);
	}
	return 0;
}
