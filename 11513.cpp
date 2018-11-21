#include <stdio.h>
#include <map>

#define GOAL 123456789
#define SIZ 3700000

int q[SIZ], qs[SIZ], qk[SIZ], qf[SIZ];
int ary[9], res[SIZ];
std::map<int, int> used;

const char *tbl[6] = {
	"H1", 
	"H2", 
	"H3", 
	"V1", 
	"V2", 
	"V3"
};
int mov[6][9] = {
	{2, 0, 1, 3, 4, 5, 6, 7, 8}, 
	{0, 1, 2, 5, 3, 4, 6, 7, 8}, 
	{0, 1, 2, 3, 4, 5, 8, 6, 7}, 
	{3, 1, 2, 6, 4, 5, 0, 7, 8}, 
	{0, 4, 2, 3, 7, 5, 6, 1, 8}, 
	{0, 1, 5, 3, 4, 8, 6, 7, 2}
};

int main()
{
	int cnt, t, d, i, j, k, l;
	cnt = 0;
	while (scanf("%d", &t) == 1)
	{
		if (!t)
		{
			break;
		}
		d = t;
		for (i=0; i<3; i++)
		{
			for (j=0; j<3; j++)
			{
				if (i || j)
				{
					scanf("%d", &t);
					d = d*10 + t;
				}
			}
		}
		++cnt;
		q[0] = d;
		qs[0] = 0;
		used[d] = cnt;
		for (i=0, j=1; i<j; i++)
		{
			d = q[i];
			if (d == GOAL)
			{
				break;
			}
			for (k=8; k>=0; k--, d/=10)
			{
				ary[k] = d%10;
			}
			for (k=0; k<6; k++)
			{
				d = 0;
				for (l=0; l<9; l++)
				{
					d = d*10 + ary[mov[k][l]];
				}
				if (used[d] != cnt)
				{
					used[d] = cnt;
					q[j] = d;
					qs[j] = qs[i]+1;
					qk[j] = k;
					qf[j] = i;
					++j;
				}
			}
		}
		if (i >= j)
		{
			puts("Not solvable");
		}
		else
		{
			printf("%d", qs[i]);
			if (qs[i])
			{
				putchar(' ');
				for (j=0; i; j++, i=qf[i])
				{
					res[j] = qk[i];
				}
				for (--j; j>=0; j--)
				{
					printf("%s", tbl[res[j]]);
				}
			}
			puts("");
		}
	}
	return 0;
}
