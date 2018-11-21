#include<stdio.h>
int sum[10];
long long count(int num)
{
	if(!num)
	{
		return 0;
	}
	long long tmp;
	tmp=num/10;
	return tmp*45+sum[num%10]+count(tmp);
}
int main()
{
	int p,q;
	long long low,high;
	sum[0]=0;
	for(p=1;p<10;p++)
	{
		sum[p]=sum[p-1]+p;
	}
	while(scanf("%d%d",&p,&q)==2)
	{
		if(p<0&&q<0)
		{
			break;
		}
		else
		{
			if(p)
			{
				low=count(p-1);
			}
			else
			{
				low=0;
			}
		}
		high=count(q);
		printf("%lld\n",high-low);
	}
	return 0;
}