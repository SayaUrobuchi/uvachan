#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[50001];
int abcc(int x)
{
	if(k[x]<1)
	{
		return x;
	}
	k[x]=abcc(k[x]);
	return k[x];
}
int bcaa(int x)
{
	if(k[x]<1)
	{
		return k[x];
	}
	return bcaa(k[x]);
}
int main()
{
	h=0;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a==0&&b==0)
		{
			break;
		}
		if(b==0)
		{
			printf("Case %d: %d\n",++h,a);
			continue;
		}
		for(c=1;c<=a;c++)
		{
			k[c]=-1;
		}
		for(c=0;c<b;c++)
		{
			scanf("%d%d",&d,&e);
			if(d==e)
			{
				continue;
			}
			if(d>e)
			{
				f=d;
				d=e;
				e=f;
			}
			if(k[e]==d)
			{
				continue;
			}
			if(k[d]>0)
			{
				if(k[d]==k[e])
				{
					continue;
				}
				f=abcc(e);
				g=abcc(k[d]);
				if(g==f)
				{
					continue;
				}
				if(f>g)
				{
					k[f]=g;
					k[e]=abcc(e);
				}
				else
				{
					k[g]=f;
					k[d]=abcc(k[d]);
				}
			}
			else
			{
				if(k[e]>0)
				{
					f=abcc(k[e]);
					if(f>d)
					{
						k[f]=d;
						k[e]=abcc(k[e]);
					}
					else
					{
						k[d]=f;
					}
				}
				else
				{
					k[e]=d;
				}
			}
		}
		for(b=1,i=0;b<=a;b++)
		{
			c=bcaa(b);
			i-=c;
			c=abcc(b);
			k[c]=0;
		}
		printf("Case %d: %d\n",++h,i);
	}
	return 0;
}