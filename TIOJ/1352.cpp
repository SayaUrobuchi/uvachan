#include <stdio.h>
#include <string.h>

#define BASE 100000000

int base, ary[1000], target[1000];
char s[2000], t[2000];

int cmp(int *p, int pl, int *q, int ql)
{
	int i;
	if(pl != ql)
	{
		return pl-ql;
	}
	for(i=pl-1; i>=0; i--)
	{
		if(p[i] != q[i])
		{
			return p[i] - q[i];
		}
	}
	return 0;
}

int main()
{
	int i, j, bl, tl;
	while(scanf("%d%s", &base, s) == 2)
	{
		memset(ary, 0, sizeof(ary));
		ary[0] = 1;
		bl = 1;
		for(i=strlen(s)-8, j=0; i>0; i-=8, j++)
		{
			sscanf(s+i, "%8d", &target[j]);
		}
		sprintf(t, "%%%dd\0", 8+i);
		sscanf(s, t, &target[j++]);
		tl = j;
		for(i=0; ; i++)
		{
			for(j=0; j<bl; j++)
			{
				ary[j] *= base;
			}
			for(j=0; j<bl; j++)
			{
				if(ary[j] >= BASE)
				{
					ary[j+1] += ary[j] / BASE;
					ary[j] %= BASE;
				}
			}
			for(; ary[j]; j++)
			{
				if(ary[j] >= BASE)
				{
					ary[j+1] += ary[j] / BASE;
					ary[j] %= BASE;
				}
			}
			bl = j;
			if(cmp(ary, bl, target, tl) > 0)
			{
				break;
			}
		}
		printf("%d\n", i);
	}
	return 0;
}
