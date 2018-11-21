#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h;
	double i,j,m;
	char k[10],l[10],n;
	g=0;
	while(scanf("%d%d",&a,&b)==2)
	{
		for(c=0,i=0;c<b;c++)
		{
			scanf("%d",&k[c]);
			i+=k[c];
			l[c]=0;
		}
		printf("Set #%d\n",++g);
		i/=a;
		for(c=0,d=-1,h=b-a,j=0;c<a;c++)
		{
			printf(" %d:",c);
			e=d;
			while(l[++e]);
			d=e;
			printf("%d %d\n",h,a-c);
			if(!h)
			{
				printf(" %d\n",k[d]);
				l[e]=1;
				if(k[e]>i)
				{
					j+=k[e]-i;
				}
				else
				{
					j+=i-k[e];
				}
			}
			else
			{
				l[e]=1;
				if(h==a-c)
				{
					m=10000;
				}
				else
				{
					if(i>k[e])
					{
						m=i-k[e];
					}
					else
					{
						m=k[e]-i;
					}
				}
				n=e;
				for(f=e+1;f<b;f++)
				{
					if(!l[f])
					{printf("123123 %g\n",k[e]+k[f]-i);
						if(k[e]+k[f]-i<m&&i-k[e]-k[f]<m)
						{
							m=k[e]+k[f]-i;
							if(m<0)
							{
								m*=-1;
							}
							n=f;
						}
					}
				}
				if(n==e)
				{
					printf(" %d\n",k[e]);
				}
				else
				{
					j+=m;
					l[n]=1;
					printf(" %d %d\n",k[e],k[n]);
					h--;
				}
			}
		}
		printf("IMBALANCE = %.5f\n",j);
	}
	return 0;
}