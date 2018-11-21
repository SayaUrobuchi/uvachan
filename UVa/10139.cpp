#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[20][2];
	while(scanf("%d %d",&a,&b)==2)
	{
		for(c=0;c<20;c++)
		{
			k[c][1]=0;
		}
		if(b==0)
		{
			printf("0 does not divide %d!\n",a);
		}
		else if(a>=b)
		{
			printf("%d divides %d!\n",b,a);
		}
		else if(a==0)
		{
			if(b==1)
			{
			    printf("%d divides %d!\n",b,a);
			}
			else
			{
				printf("%d does not divide %d!\n",b,a);
			}
		}
		else
		{
			c=(int)(sqrt(b));
			for(d=b,f=-1,e=0;e<32;e++)
			{
				if(d%2==0)
				{
					d/=2;
					k[0][0]=2;
					k[0][1]++;
					f=0;
				}
			}
			for(e=1,g=3,i=3;g<=c;g+=2)
			{
				if(d%g==0)
				{
					if(k[f][0]!=g)
					{
	                    f++;
						k[f][0]=g;
					}
					d/=g;
					k[f][1]++;
					g-=2;
				}
			}
			if(d!=1)
			{
				f++;
				k[f][0]=d;
				k[f][1]++;
			}
			for(c=0,g=0;c<=f;c++)
			{
				for(d=a,e=0;d!=1;)
				{
					e+=d/k[c][0];
					d/=k[c][0];
					if(d==1||d==0)
					{
						break;
					}
				}
				if(e<k[c][1])
				{
					printf("%d does not divide %d!\n",b,a);
					g++;
					break;
				}
			}
			if(g==0)
			{
				printf("%d divides %d!\n",b,a);
			}
		}
	}
	return 0;
}
