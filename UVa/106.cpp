#include<stdio.h>
#include<math.h>
#include<string.h>
int a,b,c,d,e,f,g,h,i,j;
bool k[5000001];
int abcc(int x,int y)
{
	while(1)
	{
		x%=y;
		if(x<2)
		{
			return x;
		}
		y%=x;
		if(y<2)
		{
			return y;
		}
	}
}
int main()
{
	int x,y,z;
	while(scanf("%d",&g)==1)
	{
		memset(k,0,sizeof(int)*(g+1));
		if(g<5)
		{
			printf("0 %d\n",g);
			continue;
		}
		for(a=2,i=0;;a++)
		{
			for(b=1;b<a;b++)
			{
				c=a*a;
				d=b*b;
				e=c+d;
				if(e>g)
				{
					break;
				}
				c-=d;
				d=2*a*b;
				x=c;
				y=d;
				z=e;
				while(1)
				{
					k[x]=1;
					k[y]=1;
					k[z]=1;
					x+=c;
					y+=d;
					z+=e;
					if(z>g)
					{
						break;
					}
				}
				j=abcc(c,d);
				j+=abcc(d,e);
				j+=abcc(c,e);
				if(j==3)
				{
					i++;
				}
			}
			if(b==1)
			{
				break;
			}
		}
		for(a=0,j=0;a<=g;a++)
		{
			j+=k[a];
		}
		j-=g;
		j*=-1;
		printf("%d %d\n",i,j);
	}
	return 0;
}