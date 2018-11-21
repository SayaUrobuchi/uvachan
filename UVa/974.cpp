#include<stdio.h>
int a,b,c,d,f,g,h,i,j,k[100],l[10];
double e;
int main()
{
	char check;
	check = 0;
	for(a=1,b=0;b<10;a*=10,b++)
	{
		l[b]=a;
	}
	k[0]=9;
	for(a=45,b=1,c=1,d=2,e=10000,f=2025;a<40001;)
	{
		for(g=d;l[g]<f&&g<10;g++)
		{
			i=f/l[g];
			j=f%l[g];
			if(i+j==a&&j)
			{
				k[b++]=a;
				break;
			}
		}
		f+=a*2+1;
		a++;
		if(f>e)
		{
			e*=10;
			if(c)
			{
				d++;
				c=0;
			}
			else
			{
				c=1;
			}
		}
	}
	scanf("%d",&h);
	for(g=0;h>0;h--)
	{
		if(check) printf("\n");
		check = 1;
		scanf("%d%d",&a,&b);
		printf("case #%d\n",++g);
		for(c=0;c<19;c++)
		{
			if(a<k[c]+1)
			{
				break;
			}
		}
		for(d=0;c<19;c++)
		{
			if(k[c]>b)
			{
				break;
			}
			printf("%d\n",k[c]);
			d=1;
		}
		if(!d)
		{
			printf("no kaprekar numbers\n");
		}
	}
	return 0;
}
