#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	double k[20][20],m[21][20][20];
	char l[21][20][20],n[21];
	while(scanf("%d",&a)==1)
	{
		for(b=0;b<a;b++)
		{
			for(c=0;c<a;c++)
			{
				if(b==c)
				{
					k[b][c]=1;
				}
				else
				{
					scanf("%lf",&k[b][c]);
				}
				l[0][b][c]=b;
				m[0][b][c]=k[b][c];
				for(d=1;d<21;d++)
				{
					m[d][b][c]=0;
				}
			}
		}
		for(i=0,j=1;i<a;i++,j++)
		{
			for(b=0;b<a;b++)
			{
				for(c=0;c<a;c++)
				{
					for(d=0;d<a;d++)
					{
						if(m[j-1][c][b]*k[b][d]>m[j][c][d])
						{
							m[j][c][d]=m[j-1][c][b]*k[b][d];
							l[j][c][d]=b;
						}
					}
				}
			}
		}
		for(i=0,j=1;i<a;i++,j++)
		{
			for(b=0;b<a;b++)
			{
				if(m[j][b][b]>1.01)
				{
					n[j]=l[j][b][b];
					for(c=i;c>-1;c--)
					{
						n[c]=l[c][b][n[c+1]];
					}
					j++;
					break;
				}
			}
			if(b<a)
			{
				break;
			}
		}
		if(i==a)
		{
			printf("no arbitrage sequence exists\n");
		}
		else
		{
			for(b=0;b<j;b++)
			{
				printf("%d ",n[b]+1);
			}
			printf("%d\n",n[0]+1);
		}
	}
	return 0;
}