#include<stdio.h>
int main()
{
	int a,b;
	long c,d,e,f,g,h,i,j[10][100],k[10][100];
	while(scanf("%d%d",&a,&b)==2)
	{
		for(c=0,e=b-1;c<a;c++)
		{
			for(d=0;d<b;d++)
			{
				scanf("%ld",&k[c][d]);
			}
			j[c][e]=c;
		}
		a--;
		for(d=b-2,f=d+1,g=a-1;d>-1;d--,f--)
		{
			e=k[0][f];
			j[0][d]=0;
			if(a>0)
			{
				if(k[1][f]<e)
				{
					e=k[1][f];
					j[0][d]=1;
				}
			}
			if(k[a][f]<e)
			{
				e=k[a][f];
				j[0][d]=a;
			}
			k[0][d]+=e;
			for(c=1;c<a;c++)
			{
				e=k[c-1][f];
				j[c][d]=c-1;
				if(k[c][f]<e)
				{
					e=k[c][f];
					j[c][d]=c;
				}
				if(k[c+1][f]<e)
				{
					e=k[c+1][f];
					j[c][d]=c+1;
				}
				k[c][d]+=e;
			}
			if(a>0)
			{
				e=k[0][f];
				j[a][d]=0;
				if(k[g][f]<e)
				{
					e=k[g][f];
					j[a][d]=g;
				}
				if(k[a][f]<e)
				{
					e=k[a][f];
					j[a][d]=a;
				}
				k[a][d]+=e;
			}
		}
		a++;
		for(c=1,d=k[0][0],e=0;c<a;c++)
		{
			if(k[c][0]<d)
			{
				d=k[c][0];
				e=c;
			}
		}
		printf("%ld",e+1);
		for(c=1,d=j[e][0];c<b;c++)
		{
			printf(" %ld",d+1);
			d=j[d][c];
		}
		printf("\n%ld\n",k[e][0]);
	}
	return 0;
}