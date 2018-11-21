#include <stdio.h>
#include <string.h>

int ary[2050], pp[3050], buf1[15000], buf0[15000], buf2[15000];

int numcmp(int *p, int *q, int len)
{
	int i;
	for(i=len-1; i>=0; i--)
	{
		if(p[i] != q[i])
		{
			return p[i]-q[i];
		}
	}
	return 0;
}

int main()
{
	int count, i, j, k, n;
	int blen, blen1, blen2, blen0, mx, len, c, cc, p, q, *bnum, loc1, loc2;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		pp[0] = 0;
		for(i=1, j=1, mx=-1000000, c=0; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			if(ary[i] != 0)
			{
				pp[j++] = i;
			}
			if(ary[i] > mx)
			{
				mx = ary[i];
			}
			if(ary[i] < 0)
			{
				c++;
			}
		}
		loc1 = -1;
		if(c & 1)
		{
			for(i=1, j=-100000; i<=n; i++)
			{
				if(ary[i] < 0 && ary[i] > j)
				{
					j = ary[i];
					loc1 = i;
				}
			}
		}
		memset(buf0, 0, sizeof(buf0));
		buf0[0] = 1;
		blen0 = 1;
		bnum = buf0;
		blen = blen0;
		for(i=1, c=0; i<=n; i++)
		{
			if(ary[i] == 0 || i == loc1)
			{
				continue;
			}
			c++;
			cc = ary[i];
			if(ary[i] < 0)
			{
				cc = -ary[i];
			}
			for(k=0; k<blen; k++)
			{
				bnum[k] *= cc;
			}
			for(k=0; k<blen; k++)
			{
				if(bnum[k] >= 10)
				{
					bnum[k+1] += bnum[k]/10;
					bnum[k] %= 10;
				}
			}
			for(; bnum[k]; k++)
			{
				if(bnum[k] >= 10)
				{
					bnum[k+1] = bnum[k]/10;
					bnum[k] %= 10;
				}
			}
			blen = k;
			bnum[blen] = 0;
		}
		blen0 = blen;
		if(!c)
		{
			printf("%d\n", mx);
			continue;
		}
		for(i=blen0-1; i>=0; i--)
		{
			printf("%d", buf0[i]);
		}
		printf("\n");
	}
	return 0;
}
