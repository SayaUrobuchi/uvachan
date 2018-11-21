#include <stdio.h>

#define N 5000
#define UNIT 1000000000
#define LENGTH 117

int f[N+1][LENGTH];
int len[N+1];

int main()
{
	int n, i, j, temp;
	int *ptr, *l1, *l2;
	f[1][0] = 1;
	len[1] = 1;
	f[2][0] = 1;
	len[2] = 1;
	for(i=3; i<=N; i++)
	{
		for(j=0, temp=len[i-1], ptr=f[i], l1=f[i-1], l2=f[i-2]; j<temp; j++)
		{
			ptr[j] += l1[j] + l2[j];
			if(ptr[j] >= UNIT)
			{
				ptr[j] -= UNIT;
				ptr[j+1]++;
			}
		}
		for(; ptr[j]; j++)
		{
			if(ptr[j] >= UNIT)
			{
				ptr[j] -= UNIT;
				ptr[j+1]++;
			}
		}
		len[i] = j;
	}
	/*printf("%d\n", len[N]);*/
	while(scanf("%d", &n) == 1)
	{
		ptr = f[n];
		printf("The Fibonacci number for %d is %d", n, ptr[len[n]-1]);
		for(i=len[n]-2; i>=0; i--)
		{
			printf("%09d", ptr[i]);
		}
		printf("\n");
	}
	return 0;
}
