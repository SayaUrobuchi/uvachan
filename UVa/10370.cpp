#include<stdio.h>
int main()
{
	double x;
	char y;
	int a,b,c,d,e,f,g,h,i,j,k[1000];
	scanf("%d",&a);
	for(a;a>0;a--)
	{
		scanf("%d",&b);
		for(c=0,d=0;c<b;c++)
		{
			scanf("%d",&k[c]);
			d+=k[c];
		}
		d/=b;
		for(c=0,i=0;c<b;c++)
		{
			if(k[c]>d)
			{
				i++;
			}
		}
		x=i*100;
		x/=b;
		y='%';
		printf("%.3f%c\n",x,y);
	}
	return 0;
}