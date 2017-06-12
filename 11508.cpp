#include <stdio.h>
#include <string.h>

int ary[100005];
char buf[3000000];

void recurs(int n)
{
	int temp;
	if(ary[n] == n || ary[n] == ary[ary[n]])
	{
		return;
	}
	temp = ary[n];
	ary[n] = ary[temp];
	ary[temp] = temp;
	recurs(n);
}

int main()
{
	int n, i, temp;
	char *p;
	while(gets(buf))
	{
		p = strtok(buf, " ");
		n = 0;
		if(p)
		{
			do
			{
				sscanf(p, "%d", &ary[n++]);
			}while(p=strtok(NULL, " "));
		}
		if(n == 1 && ary[0] == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			if(ary[i] >= n || ary[i] < 0)
			{
				break;
			}
		}
		if(i == n)
		{
			for(i=0; i<n; i++)
			{
				recurs(i);
			}
			printf("%d", ary[0]);
			for(i=1; i<n; i++)
			{
				printf(" %d", ary[i]);
			}
			printf("\n");
		}
		else
		{
			printf("Message hacked by the Martians!!!\n");
		}
	}
	return 0;
}
