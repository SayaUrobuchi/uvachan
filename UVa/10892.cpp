#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		if(a==1)
		{
			printf("1 1\n");
			continue;
		}
		b=sqrt(a)+1;
		c=a;
		i=1;
		j=0;
		while(c%2==0)
		{
			c/=2;
			j++;
		}
		if(j>0)
		{
			i*=j*2+1;
			j=0;
		}
		for(d=3;d<b&&c>1;d+=2)
		{
			while(c%d==0)
			{
				c/=d;
				j++;
			}
			if(j>0)
			{
				i*=j*2+1;
				j=0;
			}
		}
		if(c>1)
		{
			i*=3;
		}
		i++;
		printf("%d %d\n",a,i/2);
	}
	return 0;
}