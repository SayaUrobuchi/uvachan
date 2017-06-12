#include<stdio.h>
int a,i,j,k[100][101];
char l[100],m[101];
int abcc(int p,int q)
{
	int w,x;
	if(p==a)
	{
		if(q>m[0]-1)
		{
			m[0]=1;
			for(w=0;w<a;w++)
			{
				if(l[w])
				{
					m[m[0]++]=w+1;
				}
			}
		}
		return 0;
	}
	for(w=1,x=1;w<k[p][0];w++)
	{
		if(l[k[p][w]])
		{
			x=0;
		}
	}
	l[p]=x;
	abcc(p+1,q+x);
	if(x)
	{
		l[p]=0;
		abcc(p+1,q);
	}
	return 0;
}
int main()
{
	int b,c,d,e,f,g,h;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d%d",&a,&b);
		for(c=0;c<a;c++)
		{
			k[c][0]=1;
			l[c]=0;
		}
		for(b;b>0;b--)
		{
			scanf("%d%d",&c,&d);
			c--;
			d--;
			k[c][k[c][0]++]=d;
			k[d][k[d][0]++]=c;
		}
		m[0]=1;
		abcc(0,0);
		printf("%d\n",m[0]-1);
		printf("%d",m[1]);
		for(b=2;b<m[0];b++)
		{
			printf(" %d",m[b]);
		}
		printf("\n");
	}
	return 0;
}