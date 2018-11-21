#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[120000];
char l;
int main()
{
	while(scanf("%d",&a)==1)
	{
		b=-1;
		while(scanf("%d%c",&k[++b],&l)==2)
		{
			if(l==10)
			{
				b--;
				break;
			}
		}
		for(c=1,d=1,i=0;b>-1;b--,c*=a,d++)
		{
			i+=k[b]*c*d;
		}
		printf("%d\n",i);
	}
	return 0;
}