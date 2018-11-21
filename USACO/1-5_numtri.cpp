/*
	ID: sa072682
	LANG: C
	TASK: numtri
*/
#include <stdio.h>
#include <string.h>

int ary[1002], temp[1002];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, i, j, ans;
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
	scanf("%d%d", &n, &ary[0]);
	for(i=1; i<n; i++)
	{
		scanf("%d", &temp[0]);
		temp[0] += ary[0];
		for(j=1; j<i; j++)
		{
			scanf("%d", &temp[j]);
			temp[j] += max(ary[j-1], ary[j]);
		}
		scanf("%d", &temp[j]);
		temp[j] += ary[j-1];
		memcpy(ary, temp, sizeof(ary));
	}
	for(i=0, ans=0; i<n; i++)
	{
		ans = max(ans, temp[i]);
	}
	printf("%d\n", ans);
	scanf(" ");
	return 0;
}
