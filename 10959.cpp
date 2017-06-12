#include<stdio.h>
int a,b,c,d,e,f,g,h,i[1002],j[1002],k[1002][1002],m;
int abcc(int x)
{
	int y;
	for(y=1;y<a;y++)
	{
		if(k[x][y]==1)
		{
			if(j[y]-1>j[x])
			{
				j[y]=j[x]+1;
				i[c]=y;
				c++;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&m);
	for(m;m>0;m--)
	{
		scanf("%d %d",&a,&b);
		for(c=0;c<1002;c++)
		{
			for(d=0;d<1002;d++)
			{
				k[c][d]=0;
			}
		}
		for(b;b>0;b--)
		{
			scanf("%d %d",&c,&d);
			k[c][d]=1;
			k[d][c]=1;
		}
		j[0]=0;
		for(b=1;b<a;b++)
		{
			j[b]=10000000;
		}
		for(b=1,c=0;b<a;b++)
		{
			if(k[0][b]==1)
			{
				j[b]=1;
				i[c]=b;
				c++;
			}
		}
		for(b=0;b<c;b++)
		{
			abcc(i[b]);
		}
		if(g==1)
		{
			printf("\n");
		}
		g=1;
		for(b=1;b<a;b++)
		{
			printf("%d\n",j[b]);
		}
	}
	return 0;
}