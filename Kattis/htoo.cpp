#include <iostream>
#include <cstring>

int ary[128], bry[128];
char s[1048576], t[1048576];

void rd(const char *s, int ary[])
{
	int r, num, dis;
	char c;
	memset(ary+(int)'A', 0, sizeof(int)<<5);
	while (*s)
	{
		r = sscanf(s, "%c%d%n", &c, &num, &dis);
		if (r == 1)
		{
			num = 1;
			dis = 1;
		}
		ary[c] += num;
		s += dis;
	}
}

int main()
{
	int n, i, u, ans;
	while (scanf("%s%d%s", s, &n, t) == 3)
	{
		rd(s, ary);
		rd(t, bry);
		for (i='A', ans=2e9; i<='Z'; i++)
		{
			if (bry[i])
			{
				u = ary[i] * n / bry[i];
				ans = std::min(u, ans);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
