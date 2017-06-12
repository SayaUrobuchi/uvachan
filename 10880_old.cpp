#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[2000];
	scanf("%d",&h);
	for(g=1;g<=h;g++)
	{
		scanf("%d %d",&a,&b);
		printf("Case #%d:",g);
		if(a==b)
		{
			printf(" 0");
		}
		else if(a-b>b)
		{
			c=a-b;
			d=(int)(sqrt(c));
			for(e=1,i=0;e<=d;e++)
			{
				if(c%e==0)
				{
					k[i]=e;
					i++;
				}
			}
			e=i-2;
			if(i>0)
			{
				if(k[i-1]*k[i-1]!=c)
				{
					k[i]=c/k[i-1];
					i++;
				}
			}
			for(e;e>=0;e--,i++)
			{
				k[i]=c/k[e];
			}
			for(d=0;d<i;d++)
			{
				if(k[d]>b)
				{
					printf(" %d",k[d]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}