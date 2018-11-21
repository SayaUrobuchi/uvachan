#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d,e,f,g,h;
	char check;
	double i,j;
	check = 0;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		if(check) printf("\n");
		check = 1;
		scanf("%d",&a);
		if(a==0)
		{
			printf("3\n");
			continue;
		}
		if(a<0)
		{
			a*=-1;
		}
		i=-1;
		j=a;
		j*=8;
		i+=sqrt(1+j);
		i/=2;
		b=i;
		if(b!=i)
		{
			b++;
		}
		c=b*b+b;
		c/=2;
		d=c-a;
		if(d%2==1)
		{
			if(b%2==0)
			{
				b++;
			}
			else
			{
				b+=2;
			}
		}
		/*for(;;b++)
		{
			c=b*b+b;
			c/=2;
			d=c-a;
			if(d%2==0)
			{
				break;
			}
		}*/
		printf("%d\n",b);
	}
	return 0;
}
