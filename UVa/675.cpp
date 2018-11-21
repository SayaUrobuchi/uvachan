#include <stdio.h>
#include <stdlib.h>

#define N 10005

int n, m, i, j, cnt;
int idx[N], ch[N];
char s[1048576];
	
struct point
{
	int x, y;
};

struct point p[N];

int comp(const void *a, const void *b)
{
	if(p[*(int*)a].x != p[*(int*)b].x)
	{
		return p[*(int*)a].x - p[*(int*)b].x;
	}
	else if (p[*(int*)a].y != p[*(int*)b].y)
	{
		return p[*(int*)a].y - p[*(int*)b].y;
	}
	return *(int*)a - *(int*)b;
}

long long cross(struct point p, struct point q, struct point r)
{
	return (long long)(q.x-p.x) * (r.y-p.y) - (long long)(q.y-p.y) * (r.x-p.x);
}

void solve()
{
	int lx, ly, st;
	qsort(idx, n, sizeof(int), comp);
	for (i=0, j=0; i<n; i++)
	{
		if (!i || (p[idx[i]].x != p[idx[i-1]].x || p[idx[i]].y != p[idx[i-1]].y))
		{
			idx[j++] = idx[i];
		}
	}
	n = j;
	for(i=0, m=0; i<n; i++)
	{
		for(; m>=2&&cross(p[ch[m-2]], p[ch[m-1]], p[idx[i]])<=0; m--);
		ch[m++] = idx[i];
	}
	for(i=n-2, j=m+1; i>=0; i--)
	{
		for(; m>=j&&cross(p[ch[m-2]], p[ch[m-1]], p[idx[i]])<=0; m--);
		ch[m++] = idx[i];
	}
	if (cnt)
	{
		puts("");
	}
	++cnt;
	st = 0;
	for (i=1; i<m; i++)
	{
		if (ch[i] < ch[st])
		{
			st = i;
		}
	}
	i = st;
	lx = p[ch[(i+1)%m]].x;
	ly = p[ch[(i+1)%m]].y;
	for(j=0; j<m; j++)
	{
		if (p[ch[(i+j)%m]].x != lx || p[ch[(i+j)%m]].y != ly)
		{
			printf("%d, %d\n", p[ch[(i+j)%m]].x, p[ch[(i+j)%m]].y);
		}
		lx = p[ch[(i+j)%m]].x;
		ly = p[ch[(i+j)%m]].y;
	}
	if (lx != p[ch[i]].x || ly != p[ch[i]].y)
	{
		printf("%d, %d\n", p[ch[i]].x, p[ch[i]].y);
	}
}

int main()
{
	cnt = 0;
	n = 0;
	while (gets(s))
	{
		if (!*s)
		{
			--n;
			solve();
			n = 0;
		}
		else
		{
			sscanf(s, "%d,%d", &p[n].x, &p[n].y);
			idx[n] = n;
			n++;
		}
	}
	if (n)
	{
		--n;
		solve();
	}
	return 0;
}
