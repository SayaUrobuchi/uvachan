#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[100],s;
	b=0;
	h=0;
	s=0;
	while(scanf("%d",&a)==1)
	{
		if(a==-1)
		{
			if(!b)
			{
				break;
			}
			if(s)
			{
				printf("\n");
			}
			s=1;
			printf("Test #%d:\n",++h);
			printf("  maximum possible interceptions: %d\n",b);
			b=0;
		}
		else
		{
			for(c=0;c<b;c++)
			{
				if(a>k[c])
				{
					k[c]=a;
					break;
				}
			}
			if(c==b)
			{
				k[b++]=a;
			}
		}
	}
	return 0;
}