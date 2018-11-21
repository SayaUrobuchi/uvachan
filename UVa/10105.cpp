#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[13],l;
int main()
{
	for(a=1,k[0]=1;a<13;a++)
	{
		k[a]=k[a-1]*a;
	}
	while(scanf("%d%d",&a,&b)==2)
	{
		i=k[a];
		for(b;b>0;b--)
		{
			scanf("%d",&c);
			i/=k[c];
		}
		printf("%d\n",i);
	}
	return 0;
}