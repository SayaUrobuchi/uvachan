#include <stdio.h>
#include <string.h>

int m;
int zm[2][2] = {
	{1, 0}, 
	{0, 1}
};
int fm[2][2] = {
	{0, 1}, 
	{1, 1}
};
int am[2][2], bm[2][2], xm[2][2], tm[2][2];

void mul(int a[2][2], int b[2][2])
{
	int i, j, k;
	memset(tm, 0, sizeof(tm));
	for (i=0; i<2; i++)
	{
		for (j=0; j<2; j++)
		{
			for (k=0; k<2; k++)
			{
				tm[i][j] += (a[i][k] * b[k][j]) % m;
			}
		}
	}
	memcpy(a, tm, sizeof(tm));
}

int main()
{
	int count, i;
	unsigned long long a, b;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%llu%llu%d", &a, &b, &m);
		if (!b)
		{
			printf("%d\n", 1%m);
			continue;
		}
		memcpy(am, zm, sizeof(am));
		memcpy(xm, fm, sizeof(xm));
		for (i=0; i<64; i++)
		{
			if (a & (1LLU << i))
			{
				mul(am, xm);
			}
			mul(xm, xm);
		}
		memcpy(xm, am, sizeof(xm));
		memcpy(bm, zm, sizeof(bm));
		for (i=0; i<64; i++)
		{
			if (b & (1LLU << i))
			{
				mul(bm, xm);
			}
			mul(xm, xm);
		}
		printf("%d\n", bm[1][0]);
	}
	return 0;
}
