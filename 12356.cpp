#include <stdio.h>

int lnk[100005], pre[100005];

int main()
{
	int n, m, i, p, q, l, r;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			lnk[i] = i+1;
			pre[i+1] = i;
		}
		lnk[i] = 0;
		while (m--)
		{
			scanf("%d%d", &p, &q);
			l = pre[p];
			r = lnk[q];
			lnk[l] = r;
			pre[r] = l;
			printf(l?"%d":"*", l);
			printf(r?" %d\n":" *\n", r);
		}
		puts("-");
	}
	return 0;
}
