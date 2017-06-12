#include <stdio.h>
#include <string.h>

int n, m, o, s;
int iused[110];
int pused[110];
int assigned[110];
int map[420][420];
int pfori[110];
char name[420][30];
char buf1[50], buf2[50];

int fill(int);

int search(char *t)
{
	int i;
	for(i=1; i<s; i++)
	{
		if(!strcmp(name[i], t))
		{
			return i;
		}
	}
	strcpy(name[s++], t);
	map[i][i] = 1;
	return i;
}

int assign(int now)
{
	if(!assigned[now])
	{
		return 1;
	}
	else if(!iused[assigned[now]])
	{
		return fill(assigned[now]);
	}
	return 0;
}

int fill(int now)
{
	int i;
	iused[now] = 1;
	for(i=1; i<=m; i++)
	{
		if(map[i][pfori[now]] && !pused[i])
		{
			pused[i] = 1;
			if(assign(i))
			{
				assigned[i] = now;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int count, i, j, k, ans;
	scanf("%d", &count);
	while(count--)
	{
		memset(map, 0, sizeof(map));
		scanf("%d", &m);
		for(i=1, s=m+1; i<=m; i++)
		{
			scanf("%s", name[i]);
			map[i][i] = 1;
		}
		scanf("%d", &n);
		for(i=1; i<=n; i++)
		{
			scanf("%s%s", buf1, buf2);
			pfori[i] = search(buf2);
		}
		scanf("%d", &o);
		while(o--)
		{
			scanf("%s%s", buf1, buf2);
			map[search(buf2)][search(buf1)] = 1;
		}
		for(k=1; k<s; k++)
		{
			for(i=1; i<s; i++)
			{
				if(map[i][k])
				{
					for(j=1; j<s; j++)
					{
						if(map[k][j])
						{
							map[i][j] = 1;
						}
					}
				}
			}
		}
		memset(assigned, 0, sizeof(assigned));
		for(i=1, ans=n; i<=n; i++)
		{
			memset(pused, 0, sizeof(pused));
			memset(iused, 0, sizeof(iused));
			ans -= fill(i);
		}
		printf("%d\n", ans);
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
