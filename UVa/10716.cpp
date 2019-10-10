#include <stdio.h>
#include <string.h>
#include <algorithm>

int tbl[128];
char s[128];

int recurs(int p, int q)
{
	int res, i, j, k, pp, qq;
	if (q-p <= 1)
	{
		return 0;
	}
	res = 0;
	for (i=p+1; i<q&&s[i]!=s[q]; i++);
	for (j=q-1; j>p&&s[j]!=s[p]; j--);
	pp = qq = 1048576;
	//if (i < q)
	if (j <= p || (i < q && i-p < q-j))
	{
		for (k=i; k>p; k--)
		{
			std::swap(s[k], s[k-1]);
		}
		pp = recurs(p+1, q-1) + (i-p);
		for (k=p; k<i; k++)
		{
			std::swap(s[k], s[k+1]);
		}
	}
	//if (j > p)
	else
	{
		for (k=j; k<q; k++)
		{
			std::swap(s[k], s[k+1]);
		}
		qq = recurs(p+1, q-1) + (q-j);
		for (k=q; k>j; k--)
		{
			std::swap(s[k], s[k-1]);
		}
	}
	return pp<qq ? pp : qq;
}

int main()
{
	int count, i, gg;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", s);
		memset(tbl, 0, sizeof(tbl));
		gg = 0;
		for (i=0; s[i]; i++)
		{
			tbl[s[i]]++;
			if (tbl[s[i]] & 1)
			{
				++gg;
			}
			else
			{
				--gg;
			}
		}
		if (gg > 1)
		{
			puts("Impossible");
			continue;
		}
		printf("%d\n", recurs(0, i-1));
	}
	return 0;
}
