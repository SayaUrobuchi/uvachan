#include <stdio.h>

int list[1000000];
int hash[1000000];

int main()
{
	int n, m, i;
	m = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!hash[n])
		{
			list[m++] = n;
		}
		hash[n]++;
	}
	for(i=0; i<m; i++)
	{
		printf("%d %d\n", list[i], hash[list[i]]);
	}
	return 0;
}
