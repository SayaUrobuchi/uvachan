#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j[8],k[92][8];
bool x[8];
char y[8][8];
int abcc()
{
	int y;
	if(e==8)
	{
		for(y=0;y<8;y++)
		{
			k[f][y]=j[y];
		}
		f++;
		return 0;
	}
	for(y=0;y<8;y++)
	{
		if(x[y])
		{
			for(b=0,c=e;b<e;b++,c--)
			{
				d=y-j[b];
				if(d<0)
				{
					d*=-1;
				}
				if(d==c)
				{
					break;
				}
			}
			if(b==e)
			{
				j[e]=y;
				x[y]=0;
				e++;
				abcc();
				e--;
				x[y]=1;
			}
		}
	}
	return 0;
}
int main()
{
	for(a=0,f=0;a<4;a++)
	{
		for(b=0;b<8;b++)
		{
			x[b]=1;
		}
		x[a]=0;
		j[0]=a;
		e=1;
		abcc();
	}
	for(a=f-1;a>-1;a--,f++)
	{
		for(b=0;b<8;b++)
		{
			k[f][b]=7-k[a][b];
		}
	}
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		for(a=0;a<8;a++)
		{
			for(b=0;b<8;b++)
			{
				scanf("%d",&y[a][b]);
			}
		}
		for(a=0,i=0;a<f;a++)
		{
			for(b=0,c=0;b<8;b++)
			{
				c+=y[k[a][b]][b];
			}
			if(c>i)
			{
				i=c;
			}
		}
		printf("%5d\n",i);
	}
	return 0;
}