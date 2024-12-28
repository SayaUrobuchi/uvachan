/*
	ID: sa072682
	LANG: C
	TASK: humble
*/
#include <stdio.h>

long long ary[100], count[100], list[100001];

int main()
{
	int n, m, i, j;
	long long minimum, temp;
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	list[0] = 1;
	for(i=1; i<=m; i++)
	{
		for(j=0, minimum=-1; j<n; j++)
		{
			if(ary[j] * list[count[j]] == list[i-1])
			{
				count[j]++;
			}
			if(ary[j] * list[count[j]] < minimum || minimum == -1)
			{
				minimum = ary[j] * list[count[j]];
				temp = j;
			}
		}
		list[i] = minimum;
		count[temp]++;
	}
	printf("%lld\n", list[m]);
	scanf(" ");
	return 0;
}
