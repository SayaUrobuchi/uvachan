#include <stdio.h>

const char *key[] = {"123", "DSO", "STO", "RGP"};
int tbl[4][128];
int ary[12];
char buf[1024];

int trans(char *s)
{
	int res, i;
	for (i=0, res=0; i<4; i++)
	{
		res |= tbl[i][s[i]];
	}
	return res;
}

int main()
{
	int i, j, k, l, t, res, cc;
	for (i=0; i<4; i++)
	{
		for (j=0; j<3; j++)
		{
			tbl[i][key[i][j]] = (1 << (i*3+j));
		}
	}
	while (scanf("%s", buf) == 1)
	{
		ary[0] = trans(buf);
		for (i=1; i<12; i++)
		{
			scanf("%s", buf);
			ary[i] = trans(buf);
		}
		for (i=0, cc=0; i<12; i++)
		{
			for (j=i+1; j<12; j++)
			{
				for (k=j+1; k<12; k++)
				{
					res = (ary[i] | ary[j] | ary[k]);
					for (l=0; l<4; l++, res>>=3)
					{
						t = (res & 7);
						if (t != 1 && t != 2 && t != 4 && t != 7)
						{
							break;
						}
					}
					if (l >= 4)
					{
						printf("%d %d %d\n", i+1, j+1, k+1);
						++cc;
					}
				}
			}
		}
		if (!cc)
		{
			puts("no sets");
		}
	}
	return 0;
}
