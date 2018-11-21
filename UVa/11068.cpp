#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	double i,j;
	while(scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)==6)
	{
		if(a==0&&b==0&&c==0&&d==0&&e==0&&f==0)
		{
			break;
		}
		if(b!=0)
		{
			i=(double)a/b;
		}
		else
		{
			if(e==0)
			{
				i=(double)c/a;
				j=(double)f/d;
				if(i==j)
				{
					printf("No fixed point exists.\n");
					continue;
				}
			}
			else
			{
				i=(double)c/a;
				j=f-d*i;
				j/=e;
				printf("The fixed point is at %.2f %.2f.\n",i,j);
				continue;
			}
		}
		if(e!=0)
		{
			j=(double)d/e;
		}
		else
		{
			i=(double)f/d;
			j=c-a*i;
			j/=b;
			printf("The fixed point is at %.2f %.2f.\n",i,j);
			continue;
		}
		if(i==j)
		{
			printf("No fixed point exists.\n");
		}
		else
		{
			i=b*f-c*e;
			i/=b*d-a*e;
			j=i;
			j*=a*-1;
			j/=b;
			j+=(double)c/b;
			printf("The fixed point is at %.2f %.2f.\n",i,j);
		}
	}
	return 0;
}