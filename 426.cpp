#include <stdio.h>
#include <stdlib.h>

#define N 100000

int id[N];
int index[N];
double price[N];
char date[N][10];
char buf[2008];

int comp(const void *p, const void *q)
{
	return id[*(int*)p] - id[*(int*)q];
}

int main()
{
	int count, n, i, j, k, sq;
	scanf("%d", &count);
	gets(buf);
	gets(buf);
	while(count--)
	{
		n = 0;
		while(gets(buf))
		{
			if(!buf[0])
			{
				break;
			}
			sscanf(buf, "%s%d%lf", date[n], &id[n], &price[n]);
			/*printf("%.3lf %d\n", price[n], price[n]<1000000.0);*/
			if(price[n] < 1000000.0)
			{
				index[n] = n;
				n++;
			}
		}
		qsort(index, n, sizeof(int), comp);
		sq = (n-1) / 3 + 1;
		for(i=0; i<sq; i++)
		{
			for(j=i, k=0; j<n&&k<3; j+=sq, k++)
			{
				if(k)
				{
					printf("   ");
				}
				if(!j || id[index[j]] == id[index[j-1]]+1)
				{
					printf("%4d  %9.2lf %s", id[index[j]], price[index[j]], date[index[j]]);
				}
				else
				{
					printf("%4d* %9.2lf %s", id[index[j]], price[index[j]], date[index[j]]);
				}
			}
			printf("\n");
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
