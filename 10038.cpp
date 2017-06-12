#include<stdio.h>
int main()
{
	int a[3000],b,c,d[3000];
	while(scanf("%d",&b)==1)
	{
		c=-1;
		for(b;b>0;b--)
		{
			c++;
			scanf("%d",&a[c]);
			d[c]=c+1;
		}
		d[c]=0;
		b=c;
		for(c;c>0;c--)
		{
			a[c]-=a[c-1];
			if(a[c]<0)
			{
				a[c]*=-1;
			}
			d[a[c]-1]=0;
		}
		for(b;b>0;b--)
		{
			d[0]+=d[b];
		}
		if(d[0]==0)
		{
			printf("Jolly\n");
		}
		else
		{
			printf("Not jolly\n");
		}
	}
	return 0;
}