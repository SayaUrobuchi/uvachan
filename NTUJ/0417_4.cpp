#include <stdio.h>
#include <string.h>

int mat[128], par[128], hash[128][128], mtbl[128], ftbl[128], mlist[50], flist[50], used[128];
char buf[200000], str[200000], prio[128][128];

int find(int);

int match(int targ, int now)
{
	used[now] = 1;
	if(mat[now] == -1)
	{
		mat[now] = targ;
		return 1;
	}
	if(hash[now][targ] < hash[now][mat[now]])
	{
		if(used[mat[now]] == 0)
		{
			find(mat[now]);
			mat[now] = targ;
			return 1;
		}
	}
	return 0;
}

int find(int now)
{
	int i;
	used[now] = 1;
	for(i=0; prio[now][i]; i++)
	{
		if(used[prio[now][i]] == 0 && match(now, prio[now][i]))
		{
			par[now] = prio[now][i];
			return 1;
		}
	}
	return 0;
}

int main()
{
	int count, n, i, j, mc, fc;
	char *ptr;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		gets(buf);
		gets(buf);
		memset(mtbl, 0, sizeof(mtbl));
		memset(ftbl, 0, sizeof(ftbl));
		for(ptr=buf; *ptr; ptr++)
		{
			if(*ptr != ' ')
			{
				if(*ptr > 96)
				{
					mtbl[*ptr] = 1;
				}
				else
				{
					ftbl[*ptr] = 1;
				}
			}
		}
		for(i=97, mc=0; i<=122; i++)
		{
			if(mtbl[i])
			{
				mtbl[i] = mc;
				mlist[mc++] = i;
			}
		}
		for(i=65, fc=0; i<=90; i++)
		{
			if(ftbl[i])
			{
				ftbl[i] = fc;
				flist[fc++] = i;
			}
		}
		for(i=0; i<n+n; i++)
		{
			gets(str);
			strcpy(prio[*str], str+2);
			for(j=2; str[j]; j++)
			{
				hash[*str][str[j]] = j;
			}
		}
		memset(mat, -1, sizeof(mat));
		for(i=0; i<fc; i++)
		{
			memset(used, 0, sizeof(used));
			find(flist[i]);
		}
		for(i=0; i<mc; i++)
		{
			printf("%c %c\n", mlist[i], mat[mlist[i]]);
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
