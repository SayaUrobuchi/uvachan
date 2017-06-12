#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	scanf("%d",&a);
	for(a;a>0;a--)
	{
		scanf("%d %d",&b,&c);
		b-=2;
		c-=2;
		d=b%3;
		e=c%3;
		b/=3;
		c/=3;
		if(d>0)
		{
			b++;
		}
		if(e>0)
		{
			c++;
		}
		printf("%d\n",b*c);
	}
	return 0;
}