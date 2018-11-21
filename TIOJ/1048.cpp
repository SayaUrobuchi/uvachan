#include <stdio.h>
#include <string.h>

int n, n_level[13], used[13];

int find_next(int now, int *require)
{
	int i, temp;
	temp = *require / n_level[now] + 1;
	*require %= n_level[now];
	for(i=0; i<n&&temp; i++)
	{
		temp -= (used[i] == 0);
		if(temp == 0)
		{
			break;
		}
	}
	used[i] = 1;
	return i+65;
}

int main()
{
	int m, i;
	char fmt[20];
	n_level[0] = 1;
	for(i=1; i<=12; i++)
	{
		n_level[i] = n_level[i-1] * i;
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		m--;
		m %= n_level[n];
		memset(used, 0, sizeof(used));
		for(i=0; i<n; i++)
		{
			strcpy(fmt, i!=n-1 ? "%c " : "%c\n");
			printf(fmt, find_next(n-i-1, &m));
		}
	}
	return 0;
}
