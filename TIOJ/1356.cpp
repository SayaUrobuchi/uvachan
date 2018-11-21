#include <stdio.h>

int c;

void move(int disc, int start, int goal)
{
	int temp;
	if(disc > 1)
	{
		temp = 6 - start - goal;
		if(temp + start == 4)
		{
			move(disc-1, start, goal);
			move(disc-1, goal, temp);
		}
		else
		{
			move(disc-1, start, temp);
		}
	}
	printf("#%d : move the dish from #%d to #%d\n", c++, start, goal);
	if(disc > 1)
	{
		if(temp + goal == 4)
		{
			move(disc-1, temp, start);
			move(disc-1, start, goal);
		}
		else
		{
			move(disc-1, temp, goal);
		}
	}
}

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		move(n, c=1, 2);
		move(n, 2, 3);
	}
	return 0;
}
