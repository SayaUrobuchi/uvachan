#include <stdio.h>

int ary[1025];

int main()
{
	int n, i;
	freopen("XD.txt", "w", stdout);
	n = 0;
	while(scanf("%d", &ary[n]) == 1)
	{
		if(ary[n] == -1)
		{
			break;
		}
		n++;
	}
	i = 0;
	while(scanf("%d", &n) == 1)
	{
		if(n != ary[i])
		{
			printf("%d: %d %d\n", i, n, ary[n]);
		}
		i++;
	}
	return 0;
}
