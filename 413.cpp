#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[35];
	double x,y;
	while(scanf("%d",&k[0])==1)
	{
		if(k[0]==0)
		{
			break;
		}
		for(a=1,e=0,f=0,g=0,h=0,i=0,j=0;a<35;a++)
		{
			scanf("%d",&k[a]);
			if(k[a]==0)
			{
				break;
			}
			b=k[a]-k[a-1];
			if(b==0)
			{
				h++;
				continue;
			}
			if(b<0)
			{
				if(g==0||g==1)
				{
					j+=h;
				}
				else
				{
					i+=h;
				}
				if(g!=1)
				{
					f++;
				}
				g=1;
				j++;
				h=0;
				continue;
			}
			if(g==0||g==2)
			{
				i+=h;
			}
			else
			{
				j+=h;
			}
			if(g!=2)
			{
				e++;
			}
			g=2;
			i++;
			h=0;
		}
		if(g==1)
		{
			j+=h;
		}
		else if(g==2)
		{
			i+=h;
		}
		if(e==0)
		{
			x=0;
		}
		else
		{
			x=i;
			x/=e;
		}
		if(f==0)
		{
			y=0;
		}
		else
		{
			y=j;
			y/=f;
		}
		printf("Nr values = %d:  %lf %lf\n",a,x,y);
	}
	return 0;
}