#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	bool k[500][500];
	while(scanf("%d%d%d",&a,&b,&h)==3)
	{
		if(a==0&&b==0&&h==0)
		{
			break;
		}
		for(c=0;c<a;c++)
		{
			for(d=0;d<b;d++)
			{
				k[c][d]=1;
			}
		}
		for(h;h>0;h--)
		{
			scanf("%d%d",&c,&d);
			scanf("%d%d",&e,&f);
			if(c>e)
			{
				g=c;
				c=e;
				e=g;
			}
			if(d>f)
			{
				g=d;
				d=f;
				f=g;
			}
			for(c--;c<e;c++)
			{
				for(g=d-1;g<f;g++)
				{
					k[c][g]=0;
				}
			}
		}
		for(c=0,i=0;c<a;c++)
		{
			for(d=0;d<b;d++)
			{
				i+=k[c][d];
			}
		}
		if(i==0)
		{
			printf("There is no empty spots.\n");
		}
		else if(i==1)
		{
			printf("There is one empty spot.\n");
		}
		else
		{
			printf("There are %d empty spots.\n",i);
		}
	}
	return 0;
}