/*
	ID: sa072682
	LANG: C
	TASK: ariprog
*/
#include <stdio.h>
#include <stdlib.h>

int ary[100000];
char tbl[125001];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int n, m, i, j, k, l, lim, len, ans, temp, temp2, left;
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(i=0; i<=m; i++)
	{
		for(j=i; j<=m; j++)
		{
			tbl[i*i+j*j] = 1;
		}
	}
	for(i=0, len=0, lim=m*m+m*m; i<=lim; i++)
	{
		if(tbl[i])
		{
			ary[len++] = i;
		}
	}
	for(i=1, lim=m*m+m*m, ans=1, temp2=n-1; ; i++, temp2+=n-1)
	{
		for(j=0, l=0; j<len&&ary[j]+temp2<=lim; j++)
		{
			for(k=0, temp=ary[j]; k<n&&tbl[temp]; k++, temp+=i);
			if(k == n)
			{
				printf("%d %d\n", ary[j], i);
				ans = 0;
			}
		}
		if(!j)
		{
			break;
		}
	}
	if(ans)
	{
		printf("NONE\n");
	}
	return 0;
}
