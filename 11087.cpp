#include<stdio.h>
#include<stdlib.h>
struct abc
{
	int q,w;
	struct abc *x,*y;
	bool z;
};
int a,b,c,d,e,f,g,h,i,j,l[501];
int main()
{
	struct abc *x,*y;
	scanf("%d",&h);
	x=(struct abc*)malloc(sizeof(abc));
	x->q=0;
	x->x=NULL;
	x->y=NULL;
	x->z=1;
	for(g=0;h>0;h--)
	{
		scanf("%d%d",&a,&b);
		for(c=0;c<b;c++)
		{
			l[c]=0;
		}
		for(c=0,i=0;c<a;c++)
		{
			scanf("%d",&d);
			y=x;
			while(1)
			{
				if(y->q!=g)
				{
					y->q=g;
					y->w=d;
					y->z=1;
					if(d<0)
					{
						d*=-1;
					}
					l[d%b]++;
					break;
				}
				if(d==y->w)
				{
					i+=y->z;
					y->z=0;
					break;
				}
				else if(d>y->w)
				{
					if(y->y==NULL)
					{
						y->y=(struct abc*)malloc(sizeof(abc));
						y=y->y;
						y->q=g;
						y->w=d;
						y->x=NULL;
						y->y=NULL;
						y->z=1;
						if(d<0)
						{
							d*=-1;
						}
						l[d%b]++;
						break;
					}
					y=y->y;
				}
				else
				{
					if(y->x==NULL)
					{
						y->x=(struct abc*)malloc(sizeof(abc));
						y=y->x;
						y->q=g;
						y->w=d;
						y->x=NULL;
						y->y=NULL;
						y->z=1;
						if(d<0)
						{
							d*=-1;
						}
						l[d%b]++;
						break;
					}
					y=y->x;
				}
			}
		}
		if(l[0])
		{
			i+=((l[0]-1)*l[0])/2;
		}
		for(c=1,d=b-1;c<d;c++,d--)
		{
			i+=l[c]*l[d];
		}
		if(c==d&&l[c])
		{
			i+=((l[c]-1)*l[c])/2;
		}
		printf("Case %d: %d\n",++g,i);
	}
	return 0;
}