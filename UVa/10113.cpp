#include <stdio.h>
#include <string.h>

int n, index1, index2;
int map1[61][61], map2[61][61];
int chk[61];
char name[61][31];
char str[1000];
char s1[1000], s2[1000];

int gcd(int p, int q)
{
	if(p % q)
	{
		return gcd(q, p%q);
	}
	return q;
}

int sfind(char *s)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(!strcmp(name[i], s))
		{
			return i;
		}
	}
	strcpy(name[n++], s);
	return i;
}

int getindex(char *s)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(!strcmp(name[i], s))
		{
			break;
		}
	}
	return i;
}

int dfs(int now, int srate, int nrate, int target)
{
	int i, left, right, temp;
	if(now == target)
	{
		printf("%d %s = %d %s\n", srate, name[index1], nrate, name[index2]);
		return 1;
	}
	for(i=0; i<n; i++)
	{
		if(map1[now][i] && !chk[i])
		{
			chk[i] = 1;
			left = srate * map1[now][i];
			right = nrate * map2[now][i];
			temp = gcd(left, right);
			left /= temp;
			right /= temp;
			if(dfs(i, left, right, target))
			{
				return 1;
			}
			chk[i] = 0;
		}
	}
	return 0;
}

int main()
{
	int r1, r2;
	n = 0;
	while(scanf("%s", str) == 1)
	{
		if(str[0] == '.')
		{
			break;
		}
		else if(str[0] == '!')
		{
			scanf("%d%s%*s%d%s", &r1, s1, &r2, s2);
			index1 = sfind(s1);
			index2 = sfind(s2);
			map1[index1][index2] = r1;
			map2[index1][index2] = r2;
			map1[index2][index1] = r2;
			map2[index2][index1] = r1;
		}
		else
		{
			scanf("%s%*s%s", s1, s2);
			index1 = getindex(s1);
			index2 = getindex(s2);
			memset(chk, 0, sizeof(chk));
			chk[index1] = 1;
			if(!dfs(index1, 1, 1, index2))
			{
				printf("? %s = ? %s\n", s1, s2);
			}
		}
	}
	return 0;
}
