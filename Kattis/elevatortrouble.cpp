#include <iostream>

int ucnt, used[1048576];
int qq[1048576], qs[1048576];

int main()
{
	int n, st, ed, up, dw, nxt, i, j;
	bool found;
	while (scanf("%d%d%d%d%d", &n, &st, &ed, &up, &dw) == 5)
	{
		++ucnt;
		used[st] = ucnt;
		qq[0] = st;
		qs[st] = 0;
		found = false;
		for (i=0, j=1; i<j; i++)
		{
			if (qq[i] == ed)
			{
				found = true;
				break;
			}
			nxt = qq[i] + up;
			if (nxt <= n && used[nxt] != ucnt)
			{
				used[nxt] = ucnt;
				qq[j] = nxt;
				qs[nxt] = qs[qq[i]] + 1;
				++j;
			}
			nxt = qq[i] - dw;
			if (nxt >= 1 && used[nxt] != ucnt)
			{
				used[nxt] = ucnt;
				qq[j] = nxt;
				qs[nxt] = qs[qq[i]] + 1;
				++j;
			}
		}
		if (found)
		{
			printf("%d\n", qs[ed]);
		}
		else
		{
			puts("use the stairs");
		}
	}
	return 0;
}
