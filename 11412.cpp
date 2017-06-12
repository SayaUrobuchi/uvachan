#include <stdio.h>
#include <string.h>

int n;
int used[10];
int tbl[128];
char s1[2008], s2[2008];
char ary[2000][10];
char list[10];

void dfs(int depth)
{
	int i;
	if(depth == 4)
	{
		strcpy(ary[n++], list);
		return;
	}
	for(i=1; i<=6; i++)
	{
		if(!used[i])
		{
			used[i] = 1;
			list[depth] = i;
			dfs(depth+1);
			used[i] = 0;
		}
	}
}

void deal(char *s)
{
	for(; *s; s++)
	{
		*s = tbl[*s];
	}
}

int check(char *p, char *s, int a, int b)
{
	int i, ta, tb;
	int num[7];
	memset(num, 0, sizeof(num));
	for(i=0, ta=tb=0; i<4; i++)
	{
		if(p[i] == s[i])
		{
			ta++;
		}
		else
		{
			num[p[i]]++;
		}
	}
	for(i=0; i<4; i++)
	{
		if(num[s[i]])
		{
			num[s[i]]--;
			tb++;
		}
	}
	return ta == a && tb == b;
}

int main()
{
	int count, i, a1, a2, b1, b2;
	n = 0;
	dfs(0);
	tbl['R'] = 1;
	tbl['G'] = 2;
	tbl['B'] = 3;
	tbl['Y'] = 4;
	tbl['O'] = 5;
	tbl['V'] = 6;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%d%d%s%d%d", s1, &a1, &b1, s2, &a2, &b2);
		deal(s1);
		deal(s2);
		for(i=0; i<n; i++)
		{
			if(check(ary[i], s1, a1, b1) && check(ary[i], s2, a2, b2))
			{
				break;
			}
		}
		if(i == n)
		{
			printf("Cheat\n");
		}
		else
		{
			printf("Possible\n");
		}
	}
	return 0;
}
