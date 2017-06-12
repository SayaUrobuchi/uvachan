#include<stdio.h>
#include<math.h>
int abcc(int x,int y)
{
	if(x>y)
	{
		x%=y;
		if(x==0)
		{
			return y;
		}
		else if(x==1)
		{
			return x;
		}
	}
	while(1)
	{
		y%=x;
		if(y==0)
		{
			return x;
		}
		else if(y==1)
		{
			return y;
		}
		x%=y;
		if(x==0)
		{
			return y;
		}
		else if(x==1)
		{
			return x;
		}
	}
}
int main()
{
	int a,b,c,d,e,f,g,h,k[55];
	double i,j;
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		for(b=0;b<a;b++)
		{
			scanf("%d",&k[b]);
		}
		for(b=0,f=0;b<a;b++)
		{
			if(k[b]%2==0)
			{
				d=1;
				for(c=b+1;c<a;c++)
				{
					if(k[c]%2==0)
					{
						continue;
					}
					e=abcc(k[b],k[c]);
					if(e==1)
					{
						f++;
					}
				}
			}
			else
			{
				d=0;
				for(c=b+1;c<a;c++)
				{
					e=abcc(k[b],k[c]);
					if(e==1)
					{
						f++;
					}
				}
			}
		}
		if(f==0)
		{
			printf("No estimate for this data set.\n");
			continue;
		}
		b=a;
		b*=a-1;
		b/=2;
		i=f/6.0;
		j=b/i;
		j=sqrt(j);
		printf("%lf\n",j);
	}
	return 0;
}