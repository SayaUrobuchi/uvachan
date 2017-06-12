#include <stdio.h>
#include <algorithm>

int ary[100005], idd[100005];
int loc[1000005];

bool comp(int p, int q)
{
	return ary[p] < ary[q];
}

int main()
{
	int n, m, i, j, p, q;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			idd[i] = i;
		}
		std::stable_sort(idd, idd+n, comp);
		for(i=0; i<n; i=j)
		{
			p = ary[idd[i]];
			loc[p] = i;
			for(j=i+1; ary[idd[j]]==p&&j<n; j++);
		}
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &q, &p);
			--q;
			j = loc[p]+q;
			if(j < n && ary[idd[j]] == p)
			{
				printf("%d\n", idd[j]+1);
			}
			else
			{
				printf("0\n");
			}
		}
	}
	return 0;
}
