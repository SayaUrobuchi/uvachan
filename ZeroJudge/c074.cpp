#include<stdio.h>
int a,b,c,d,e,f,g=0,h,i,j[6],k[13];
int abcc()
{
	int x,y,z;
	y=a-d;
	z=b;
	for(x=z;x<y;x++)
	{
		if(c==5)
		{
			printf("%d",j[0]);
			for(i=1;i<5;i++)
			{
				printf(" %d",j[i]);
			}
			printf(" %d",k[x]);
			printf("\n");
		}
		else
		{
			j[c]=k[x];
			c++;
			d--;
			b=x+1;
			abcc();
			b=z;
			d++;
			c--;
		}
	}
	return 0;
}
int main()
{
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		for(b=1;b<=a;b++)
		{
			scanf("%d",&k[b]);
		}
		b=1;
		c=0;
		d=4;
		if(g==1)
		{
			printf("\n");
		}
		g=1;
		abcc();
	}
	return 0;
}
