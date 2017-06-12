#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[21];
int abcc()
{
	int y;
	if(c==a)
	{
		if(j+k[b]>=i)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(c==b)
	{
		c++;
		y=abcc();
		c--;
		return y;
	}
	c++;
	y=abcc();
	c--;
	if(j+k[c]>=i)
	{
		return y;
	}
	j+=k[c];
	c++;
	y+=abcc();
	c--;
	j-=k[c];
	return y;
}
int main()
{
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d",&g);
		a=1;
		i=0;
		for(g;g>0;g--)
		{
			scanf("%d",&k[a]);
			i+=k[a++];
		}
		i++;
		i/=2;
		for(b=1;b<a;b++)
		{
			c=1;
			j=0;
			d=abcc();
			printf("party %d has power index %d\n",b,d);
		}
		printf("\n");
	}
	return 0;
}