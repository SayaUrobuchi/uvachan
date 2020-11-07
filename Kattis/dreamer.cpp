#include <iostream>
#include <algorithm>

int ans, dd, mm, yyyy;
int ary[16];
bool used[16];
int mt[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char path[16];

bool valid(int d, int m, int y)
{
	bool leap;
	leap = (y%400==0 || (y%100 && (y&3)==0));
	return y >= 2000 && m >= 1 && m <= 12 && d >= 1 && d <= mt[m]+(m==2&&leap?1:0);
}

void check()
{
	int d, m, y;
	sscanf(path, "%2d%2d%4d", &d, &m, &y);
	if (valid(d, m, y))
	{
		if (d+(m<<6)+(y<<12) < dd+(mm<<6)+(yyyy<<12))
		{
			dd = d;
			mm = m;
			yyyy = y;
		}
		++ans;
	}
}

void dfs(int depth)
{
	int i, last;
	if (depth == 8)
	{
		check();
		return;
	}
	for (i=0, last=-1; i<8; i++)
	{
		if (!used[i] && ary[i] != last)
		{
			path[depth] = ary[i] + '0';
			used[i] = true;
			dfs(depth+1);
			used[i] = false;
			last = ary[i];
		}
	}
}

int main()
{
	int count, i;
	scanf("%d", &count);
	while (count--)
	{
		for (i=0; i<8; i++)
		{
			scanf("%1d", &ary[i]);
		}
		std::sort(ary, ary+8);
		ans = 0;
		yyyy = dd = mm = 16384;
		dfs(0);
		if (ans == 0)
		{
			puts("0");
		}
		else
		{
			printf("%d %02d %02d %04d\n", ans, dd, mm, yyyy);
		}
	}
	return 0;
}
