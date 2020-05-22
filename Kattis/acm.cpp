#include <stdio.h>

int wa[128];
char pid[1024], res[1024];

int main()
{
	int t, solved, penalty;
	solved = 0;
	penalty = 0;
	while (scanf("%d", &t) == 1)
	{
		if (t < 0)
		{
			break;
		}
		scanf("%s%s", pid, res);
		if (*res == 'r')
		{
			solved++;
			penalty += wa[*pid] + t;
		}
		else
		{
			wa[*pid] += 20;
		}
	}
	printf("%d %d\n", solved, penalty);
	return 0;
}
