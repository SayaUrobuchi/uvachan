#include <stdio.h>
#include <string.h>

int ary[230];
int tbl[60001];

int main()
{
	int count, n, i, j, temp, temp2, flag, lim;
	for(i=0; i<230; i++)
	{
		ary[i] = i * i;
		tbl[ary[i]] = i + 1;
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<130; i++)
		{
			temp = ary[i];
			if(temp + temp + temp > n)
			{
				break;
			}
			for(j=i, flag=0, lim=n-temp; j<160; j++)
			{
				temp2 = ary[j];
				if(temp2 + temp2 > lim)
				{
					break;
				}
				if(tbl[n-(temp+temp2)] > 0)
				{
					printf("%d %d %d\n", i, j, tbl[n-(temp+temp2)]-1);
					flag = 1;
					break;
				}
			}
			if(flag)
			{
				break;
			}
		}
		if(!flag)
		{
			puts("-1");
		}
	}
	return 0;
}
