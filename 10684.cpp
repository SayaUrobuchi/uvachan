#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k,l;
	while(scanf("%d",&a)==1)
	{
		if(!a)
		{
			break;
		}
		for(b=0,c=0;a>0;a--)
		{
			scanf("%d",&d);
			b+=d;
			if(b<0)
			{
				b=0;
			}
			else
			{
				if(b>c)
				{
					c=b;
				}
			}
		}
		if(c)
		{
			printf("The maximum winning streak is %d.\n",c);
		}
		else
		{
			printf("Losing streak.\n");
		}
	}
	return 0;
}