#include <stdio.h>
#include <string.h>
#include <map>

#define GOAL 123456789
#define SIZ 370000

int q[SIZ], qs[SIZ], qk[SIZ], qf[SIZ];
int ary[9];
char s[1048576];
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
	{1, 2, 0, 3, 4, 5, 6, 7, 8}, 
	{0, 1, 2, 4, 5, 3, 6, 7, 8}, 
	{0, 1, 2, 3, 4, 5, 7, 8, 6}, 
	{6, 1, 2, 0, 4, 5, 3, 7, 8}, 
	{0, 7, 2, 3, 1, 5, 6, 4, 8}, 
	{0, 1, 8, 3, 4, 2, 6, 7, 5}
};

int main()
{
	int t, d, i, j, k, l;
	char *p;
	q[0] = GOAL;
	qs[0] = 0;
	used[GOAL] = 1;
	for (i=0, j=1; i<j; i++)
	{
		d = q[i];
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
			if (!used[d])
			{
				q[j] = d;
				qs[j] = qs[i]+1;
				qk[j] = k;
				qf[j] = i;
				used[d] = j+1;
				++j;
			}
		}
	}
	//printf("%d\n", j);
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
		if (!used[d])
		{
			puts("Not solvable");
		}
		else
		{
			t = used[d]-1;
			printf("%d", qs[t]);
			if (qs[t])
			{
				p = s;
				while (t)
				{
					strcpy(p, tbl[qk[t]]);
					p += 2;
					t = qf[t];
				}
				printf(" %s", s);
			}
			puts("");
		}
	}
	return 0;
}
