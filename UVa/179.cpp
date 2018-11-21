#include <stdio.h>
#include <string.h>
#include <math.h>

int l1, l2;
int list[105];
int used[105];
int stack[105];
int tbl[105][128];
int orig[105][128];
char plain[2005];
char c1[2005], c2[2005];

void print(int step)
{
	int i, j;
	l2 = strlen(c2);
	if(l2 % step)
	{
		for(i=l2, l2=((l2-1)/step+1)*step; i<l2; i++)
		{
			c2[i] = '?';
		}
		c2[i] = 0;
	}
	for(i=0; i<l2; i+=step)
	{
		for(j=i; j<i+step; j++)
		{
			plain[i+list[j-i]] = c2[j];
		}
	}
	plain[l2] = 0;
	puts(plain);
}

int dfs(int depth, int step)
{
	int i, j;
	int ary[128];
	if(depth == step)
	{
		print(step);
		return 1;
	}
	memset(ary, 0, sizeof(ary));
	for(i=0; i<step; i++)
	{
		for(j=0; j<l1; j+=step)
		{
			if(!used[i] && c1[j+depth] == plain[j+i])
			{
				ary[i]++;
			}
		}
	}
	for(i=0; i<step; i++)
	{
		if(ary[i] == l1 / step)
		{
			used[i] = 1;
			list[depth] = i;
			if(dfs(depth+1, step))
			{
				return 1;
			}
			used[i] = 0;
		}
	}
	return 0;
}

int deal(int k)
{
	int i;
	for(i=k; i<=l1; i+=k)
	{
		if(memcmp(tbl[i], orig[i], sizeof(tbl[0])))
		{
			return 0;
		}
	}
	memset(used, 0, sizeof(used));
	return dfs(0, k);
}

int main()
{
	int i, k, sq;
	while(gets(plain))
	{
		if(!strcmp(plain, "#"))
		{
			break;
		}
		gets(c1);
		gets(c2);
		l1 = strlen(c1);
		for(i=strlen(plain); i<l1; i++)
		{
			plain[i] = '?';
		}
		plain[i] = 0;
		for(i=0; c1[i]; i++)
		{
			memcpy(tbl[i+1], tbl[i], sizeof(tbl[0]));
			tbl[i+1][c1[i]]++;
			memcpy(orig[i+1], orig[i], sizeof(orig[0]));
			orig[i+1][plain[i]]++;
		}
		for(i=1, sq=(int)sqrt((double)l1), k=0; i<=sq; i++)
		{
			if(!(l1 % i))
			{
				stack[k++] = l1 / i;
				if(deal(i))
				{
					break;
				}
			}
		}
		if(i > sq)
		{
			for(k--; k>=0; k--)
			{
				if(deal(stack[k]))
				{
					break;
				}
			}
			if(k < 0)
			{
				puts(c2);
			}
		}
	}
	return 0;
}
