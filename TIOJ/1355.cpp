#include <stdio.h>

int c;

void move(int disc, int start, int goal)
{
	int temp;
	if(disc > 1)
	{
		move(disc-1, start, temp=6-start-goal);
	}
	printf("#%d : move the dish from #%d to #%d\n", c++, start, goal);
	if(disc > 1)
	{
		move(disc-1, temp, goal);
	}
}

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		move(n, c=1, 3);
	}
	return 0;
}
