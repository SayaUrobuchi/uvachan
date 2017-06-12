#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d,e,f,g,h;
	double i,j,k;
	g=0;
	while(scanf("%d",&a)==1)
	{
		i=a-0.5;
		i*=i;
		for(b=1,c=0;b<a;b++)
		{
			j=sqrt(i-b*b);
			e=(int)(j);
			c+=e;
		}
		c*=4;
		d=a*8-4;
		if(g==1)
		{
			printf("\n");
		}
		g=1;
		printf("In the case n = %d, %d cells contain segments of the circle.\n",a,d);
		printf("There are %d cells completely contained in the circle.\n",c);
	}
	return 0;
}