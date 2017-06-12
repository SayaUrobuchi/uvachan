#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[10][2],l[10];
int abcc(int p,int q)
{
	int w,x,y;
	if(q==c)
	{
		x=k[p][0]-e;
		if(x<0)
		{
			x*=-1;
		}
		y=k[p][1]-f;
		if(y<0)
		{
			y*=-1;
		}
		x+=y;
		j+=x;
		if(j<i||!i)
		{
			i=j;
		}
		j-=x;
		return 0;
	}
	for(w=0;w<c;w++)
	{
		if(l[w])
		{
			l[w]=0;
			x=k[p][0]-k[w][0];
			if(x<0)
			{
				x*=-1;
			}
			y=k[p][1]-k[w][1];
			if(y<0)
			{
				y*=-1;
			}
			x+=y;
			j+=x;
			abcc(w,q+1);
			j-=x;
			l[w]=1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d%d%d%d%d",&a,&b,&e,&f,&g);
		for(c=0;g>0;g--,c++)
		{
			scanf("%d%d",&k[c][0],&k[c][1]);
			l[c]=1;
		}
		for(d=0,i=0;d<c;d++)
		{
			l[d]=0;
			g=k[d][0]-e;
			if(g<0)
			{
				g*=-1;
			}
			j=g;
			g=k[d][1]-f;
			if(g<0)
			{
				g*=-1;
			}
			j+=g;
			abcc(d,1);
			l[d]=1;
		}
		printf("The shortest path has length %d\n",i);
	}
	return 0;
}