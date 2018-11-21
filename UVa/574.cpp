#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[12],l[12],m[1000][13];
int abcc(int p,int q,int r)
{
	int w,x;
	if(q==a)
	{
		for(w=0;w<i;w++)
		{
			if(m[w][12]==r)
			{
				for(x=0;x<m[w][12];x++)
				{
					if(l[x]!=m[w][x])
					{
						break;
					}
				}
				if(x==m[w][12])
				{
					break;
				}
			}
		}
		if(w!=i)
		{
			return 0;
		}
		printf("%d",l[0]);
		m[i][12]=r;
		m[i][0]=l[0];
		for(w=1;w<r;w++)
		{
			printf("+%d",l[w]);
			m[i][w]=l[w];
		}
		i++;
		printf("\n");
		return 0;
	}
	else if(q>a)
	{
		return 0;
	}
	if(p==b)
	{
		return 0;
	}
	for(w=p;w<b;w++)
	{
		l[r]=k[w];
		abcc(w+1,q+k[w],r+1);
	}
	return 0;
}
int main()
{
	while(scanf("%d%d",&a,&g)==2)
	{
		if(!a&&!g)
		{
			break;
		}
		for(b=0;b<g;b++)
		{
			scanf("%d",&k[b]);
		}
		printf("Sums of %d:\n",a);
		i=0;
		abcc(0,0,0);
		if(!i)
		{
			printf("NONE\n");
		}
	}
	return 0;
}