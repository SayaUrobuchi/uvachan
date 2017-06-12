#include <stdio.h>
#include <string.h>

#define N 5000
#define UNIT 1000000000
#define LENGTH 117

int f[5001][117];
int len[5001];
char str[5001][1100];

int main()
{
	int n, i, j, temp;
	int *ptr, *l1, *l2;
	char *p;
	len[0] = 1;
	f[1][0] = 1;
	len[1] = 1;
	f[2][0] = 1;
	len[2] = 1;
	for(i=3; i<=5000; i++)
	{
		for(j=0, temp=len[i-1], ptr=f[i], l1=f[i-1], l2=f[i-2]; j<temp; j++)
		{
			ptr[j] += l1[j] + l2[j];
			if(ptr[j] >= 1000000000)
			{
				ptr[j] -= 1000000000;
				ptr[j+1]++;
			}
		}
		if(ptr[j])
		{
			j++;
		}
		len[i] = j;
	}
	while(scanf("%d", &n) == 1)
	{
		if(!(*str[n]))
		{
			p = str[n];
			ptr = f[n];
			sprintf(p, "The Fibonacci number for %d is %d\0", n, ptr[len[n]-1]);
			p += strlen(p);
			for(i=len[n]-2; i>=0; i--)
			{
				sprintf(p, "%09d\0", ptr[i]);
				p += strlen(p);
			}
			*p = 0;
		}
		puts(str[n]);
	}
	return 0;
}
