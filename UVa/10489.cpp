#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	scanf("%d",&g);
	for(g;g>0;g--)
	{
		scanf("%d %d",&h,&k);
		for(i=0;k>0;k--)
		{
			scanf("%d %d",&f,&b);
			for(a=1;a<f;a++)
			{
				scanf("%d",&c);
				b*=c%h;
				b%=h;
			}
			i+=b;
		}
		printf("%d\n",i%h);
	}
	return 0;
}