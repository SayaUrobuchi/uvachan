#include <iostream>

const int BARD = 1;

int ary[1024];
long long song[1024];

int main()
{
	int n, m, i, j, k, cnt;
	bool bard;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			song[i] = 0;
		}
		for (i=0; i<m; i++)
		{
			scanf("%d", &cnt);
			for (j=0, bard=false; j<cnt; j++)
			{
				scanf("%d", &ary[j]);
				if (ary[j] == BARD)
				{
					bard = true;
				}
			}
			if (bard)
			{
				for (j=0; j<cnt; j++)
				{
					song[ary[j]] |= (1LL << i);
				}
			}
			else
			{
				for (j=0; j<cnt; j++)
				{
					for (k=0; k<cnt; k++)
					{
						song[ary[j]] |= song[ary[k]];
					}
				}
			}
		}
		for (i=1; i<=n; i++)
		{
			if (song[i] == song[BARD])
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}
