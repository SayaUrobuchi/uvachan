#include <iostream>
using namespace std;

int dice[3][6];

double calc(int a[], int b[])
{
	int i, j;
	int win, total;
	for (i=0, win=0, total=0; i<6; i++)
	{
		for (j=0; j<6; j++)
		{
			win += (a[i] > b[j]);
			total += (a[i] != b[j]);
		}
	}
	if (total == 0)
	{
		return 0;
	}
	//printf("winrate: %.10lf\n", win/(double)total);
	return win / (double)total;
}

int main()
{
	int i, j;
	double anti;
	for (i=0; i<3; i++)
	{
		for (j=0; j<6; j++)
		{
			scanf("%d", &dice[i][j]);
		}
	}
	int ans = -1;
	for (i=0; i<3; i++)
	{
		for (j=0, anti=1; j<3; j++)
		{
			if (i != j)
			{
				//printf("comp %d with %d\n", i, j);
				double res = calc(dice[i], dice[j]);
				if (res < anti)
				{
					anti = res;
				}
			}
		}
		if (anti >= .5)
		{
			ans = i;
			break;
		}
	}
	if (ans < 0)
	{
		puts("No dice");
	}
	else
	{
		printf("%d\n", ans+1);
	}
	return 0;
}
