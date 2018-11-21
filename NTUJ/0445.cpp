#include <stdio.h>
#include <string.h>

int used[1005], hnum[1005], tnum[1005], time[1005][1005], dis[1005], dis2[1005], m;
char name[1005][35], city[35];

struct hh
{
	int f, s;
};

struct mm
{
	int c, d;
};

struct hh hash[1005][100005];
struct mm map[1005][1005];

int max(int p, int q)
{
	return p>q ? p : q;
}

int search(char *s)
{
	int i;
	for(i=0; i<m; i++)
	{
		if(strcmp(name[i], s) == 0)
		{
			return i;
		}
	}
	strcpy(name[m++], s);
	return i;
}

void dijkstra(int c, int *dd, int t)
{
	int i, j, k, td, targ, tt, mt, ft, p, q, at, abat, temp;
	dd[c] = t;
	memset(used, 0, sizeof(used));
	for(i=0; i<m; i++)
	{
		for(j=0, td=1000000; j<m; j++)
		{
			if(used[j] == 0 && dd[j] < td)
			{
				td = dd[j];
				targ = j;
			}
		}
		used[targ] = 1;
		tt = dd[targ];
		if(targ != c)
		{
			tt += 2;
		}
		mt = tt % 60;
		for(j=0; j<hnum[targ]; j++)
		{
			p = hash[targ][j].f;
			q = hash[targ][j].s;
			if(map[p][q].d != -1)
			{
				for(k=0, at=61, abat=61; k<tnum[p]; k++)
				{
					temp = (time[p][k] + map[p][q-1].d) % 60;
					if(temp < at && temp >= mt)
					{
						at = temp;
					}
					if(temp < abat)
					{
						abat = temp;
					}
				}
				if(at == 61)
				{
					at = tt - mt + 60 + abat;
				}
				else
				{
					at = tt - mt + at;
				}
				for(k=q+1; ; k++)
				{
					ft = at + map[p][k-1].d - map[p][q-1].d;
					if(used[map[p][k].c] == 0 && ft < dd[map[p][k].c])
					{
						dd[map[p][k].c] = ft;
					}
					if(map[p][k].d == -1)
					{
						break;
					}
				}
			}
		}
	}
}

int main()
{
	int n, i, j, d, loc, h, res, mmm;
	while(scanf("%d", &n) == 1)
	{
		if(n < 0)
		{
			break;
		}
		m = 0;
		memset(hnum, 0, sizeof(hnum));
		memset(tnum, 0, sizeof(tnum));
		for(i=0; i<n; i++)
		{
			for(j=1; ; j++)
			{
				scanf("%s%d", city, &d);
				loc = search(city);
				hash[loc][hnum[loc]++] = (struct hh){i, j};
				map[i][j] = (struct mm){loc, d};
				if(d != -1)
				{
					map[i][j].d += map[i][j-1].d;
				}
				else
				{
					break;
				}
			}
			scanf("%d", &tnum[i]);
			for(j=0; j<tnum[i]; j++)
			{
				scanf("%d", &time[i][j]);
			}
		}
		scanf("%d:%d%s", &h, &mmm, city);
		memset(dis, 10, sizeof(dis));
		dijkstra(search(city), dis, h*60+mmm);
		scanf("%d:%d%s", &h, &mmm, city);
		memset(dis2, 10, sizeof(dis2));
		dijkstra(search(city), dis2, h*60+mmm);
		for(i=0, res=1000000; i<m; i++)
		{
			if(dis[i] < 100000 && dis2[i] < 100000)
			{
				if(max(dis[i], dis2[i]) < res)
				{
					res = max(dis[i], dis2[i]);
					/*printf("CITY %s\n", name[i]);*/
				}
			}
		}
		if(res == 1000000)
		{
			printf("No connection\n");
		}
		else
		{
			printf("%d:%02d\n", res/60%24, res%60);
		}
	}
	return 0;
}
