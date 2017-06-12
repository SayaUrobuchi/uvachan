#include <stdio.h>
#include <string.h>

int n, subcas;
int num[12];
int ltarget[12][12];
int used[12];
char name[12][12];
char cc[12], cadmd[12], cprmd[12], co[12];
char cname[12];
char lc[12][12][12], ladmd[12][12][12], lprmd[12][12][12], lo[12][12][12];
char lname[12][12][12];

int match(char *s1, char *s2)
{
	return !strcmp(s1, "*") || !strcmp(s2, "*") || !strcmp(s1, s2);
}

int check(int p, int q)
{
	return match(cc, lc[p][q]) && match(cadmd, ladmd[p][q]) && match(cprmd, lprmd[p][q]) && match(co, lo[p][q]);
}

int search(char *s)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(!strcmp(name[i], s))
		{
			return i;
		}
	}
}

void deliver(int now)
{
	int i, target;
	used[now] = 1;
	for(i=0; i<num[now]; i++)
	{
		if(check(now, i))
		{
			target = ltarget[now][i];
			if(target == now)
			{
				printf("%d -- delivered to %s\n", subcas, name[now]);
			}
			else if(used[target])
			{
				printf("%d -- circular routing detected by %s\n", subcas, name[target]);
			}
			else
			{
				deliver(target);
			}
			return;
		}
	}
	printf("%d -- unable to route at %s\n", subcas, name[now]);
}

int main()
{
	int cas, m, i, j;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%s%d", name[i], &m);
			num[i] = m;
			for(j=0; j<m; j++)
			{
				scanf("%s%s%s%s%s", lname[i][j], lc[i][j], ladmd[i][j], lprmd[i][j], lo[i][j]);
			}
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<num[i]; j++)
			{
				ltarget[i][j] = search(lname[i][j]);
			}
		}
		scanf("%d", &m);
		printf("Scenario # %d\n", ++cas);
		for(i=1; i<=m; i++)
		{
			scanf("%s%s%s%s%s", cname, cc, cadmd, cprmd, co);
			subcas = i;
			memset(used, 0, sizeof(used));
			deliver(search(cname));
		}
		printf("\n");
	}
	return 0;
}
