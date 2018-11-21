#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sx[1000001], sy[1000001], sz[1000001], ax[1000001], ay[1000001], az[1000001];
int map[3505][3505], used[3505], dis[3505];
char str[10000001];

int ab(int t)
{
	return t<0 ? -t : t;
}

int min(int p, int q)
{
	return p<q ? p : q;
}

int main()
{
	int sn, an, i, j, mx, tar;
	long long ans;
	char *ptr;
	while(gets(str))
	{
		if(strcmp(str, "0") == 0)
		{
			break;
		}
		ptr = strtok(str, " ");
		sn = 0;
		if(ptr)
		{
			do
			{
				sx[sn] = atoi(ptr);
				ptr = strtok(NULL, " ");
				sy[sn] = atoi(ptr);
				ptr = strtok(NULL, " ");
				sz[sn] = atoi(ptr);
				sn++;
			}while(ptr=strtok(NULL, " "));
		}
		gets(str);
		ptr = strtok(str, " ");
		an = 0;
		if(ptr)
		{
			do
			{
				az[an] = atoi(ptr);
				ptr = strtok(NULL, " ");
				ax[an] = atoi(ptr);
				ptr = strtok(NULL, " ");
				ay[an] = atoi(ptr);
				an++;
			}while(ptr=strtok(NULL, " "));
		}
		if(an+sn > 3500) while(1);
		for(i=0; i<sn; i++)
		{
			for(j=0; j<sn; j++)
			{
				map[i][j] = (sy[i]>=sx[j]&&sy[j]>=sx[i]?0:min(ab(sx[i]-sx[j]), min(ab(sx[i]-sy[j]), min(ab(sy[i]-sx[j]), ab(sy[i]-sy[j]))))) + ab(sz[i]-sz[j]);
			}
			for(j=0; j<an; j++)
			{
				map[i][j+sn] = (ax[j]<=sz[i]&&ay[j]>=sz[i]?0:min(ab(ax[j]-sz[i]), ab(ay[j]-sz[i]))) + 
								(sx[i]<=az[j]&&sy[i]>=az[j]?0:min(ab(sx[i]-az[j]), ab(sy[i]-az[j])));
			}
		}
		for(i=0; i<an; i++)
		{
			for(j=0; j<sn; j++)
			{
				map[i+sn][j] = (ax[i]<=sz[j]&&ay[i]>=sz[j]?0:min(ab(ax[i]-sz[j]), ab(ay[i]-sz[j]))) + 
								(sx[j]<=az[i]&&sy[j]>=az[i]?0:min(ab(sx[j]-az[i]), ab(sy[j]-az[i])));
			}
			for(j=0; j<an; j++)
			{
				map[i+sn][j+sn] = (ay[i]>=ax[j]&&ay[j]>=ax[i]?0:min(ab(ax[i]-ax[j]), min(ab(ax[i]-ay[j]), min(ab(ay[i]-ax[j]), ab(ay[i]-ay[j]))))) + ab(az[i]-az[j]);
			}
		}
		memset(used, 0, sizeof(used));
		used[0] = 1;
		for(i=0; i<an+sn; i++)
		{
			dis[i] = map[0][i];
		}
		for(i=1, ans=0; i<an+sn; i++)
		{
			for(j=1, mx=2147483647; j<an+sn; j++)
			{
				if(used[j] == 0 && dis[j] < mx)
				{
					mx = dis[j];
					tar = j;
				}
			}
			ans += dis[tar];
			used[tar] = 1;
			for(j=1; j<an+sn; j++)
			{
				if(used[j] == 0 && dis[j] > map[tar][j])
				{
					dis[j] = map[tar][j];
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
