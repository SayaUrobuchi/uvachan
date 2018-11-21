#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	double k[10][101],l[10],m[10];
	for(a=2;a<10;a++)
	{
		for(b=0,c=a+1;b<c;b++)
		{
			l[b]=1;
		}
		k[a][1]=100;
		for(b=2;b<101;b++)
		{
			m[0]=l[0]+l[1];
			for(d=1;d<a;d++)
			{
				m[d]=l[d-1]+l[d]+l[d+1];
			}
			m[d]=l[d-1]+l[d];
			k[a][b]=0;
			for(d=0;d<c;d++)
			{
				l[d]=m[d];
				k[a][b]+=m[d];
			}
			k[a][b]*=100;
			for(e=0;e<b;e++)
			{
				k[a][b]/=c;
			}
		}
	}
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a<2)
		{
			printf("100.00000\n");
		}
		else
		{
			printf("%.5f\n",k[a][b]);
		}
	}
	return 0;
}