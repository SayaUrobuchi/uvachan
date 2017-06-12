#include <stdio.h>

int n;
int aryx[5001], aryy[5001], aryz[5001];
int tbl[11];

int main()
{
	int i, j, dis, temp, sum;
	while(scanf("%d%d%d", &aryx[n], &aryy[n], &aryz[n]) == 3)
	{
		if(!aryx[n] && !aryy[n] && !aryz[n])
		{
			break;
		}
		n++;
	}
	for(i=0; i<n; i++)
	{
		for(j=0, dis=2147483647; j<n; j++)
		{
			if(i != j)
			{
				temp = aryx[i] - aryx[j];
				sum = temp * temp;
				temp = aryy[i] - aryy[j];
				sum += temp * temp;
				temp = aryz[i] - aryz[j];
				sum += temp * temp;
				if(sum < dis)
				{
					dis = sum;
				}
			}
		}
		for(j=1; j<=10; j++)
		{
			if(dis < j * j)
			{
				tbl[j]++;
				break;
			}
		}
	}
	for(i=1; i<=10; i++)
	{
		printf("%4d", tbl[i]);
	}
	printf("\n");
	scanf(" ");
	return 0;
}
