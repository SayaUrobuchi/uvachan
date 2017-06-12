#include<stdio.h>
int a,b,c,d,f,g,h,i[80000],j[80000],k[100000];
int main()
{
	long long e;
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		i[0]=1;
		j[0]=1;
		for(b=0;b<a;b++)
		{
			scanf("%d",&k[b]);
			if(k[b]>0)
			{
				i[i[0]]=b;
				i[0]++;
			}
			else if(k[b]<0)
			{
				j[j[0]]=b;
				j[0]++;
			}
		}
		for(b=1,c=1,e=0;b<i[0];b++)
		{
			for(d=k[i[b]];d>0;c++)
			{
				if(k[j[c]]*-1>d)
				{
					k[j[c]]+=d;
					f=i[b]-j[c];
					if(f<0)
					{
						f*=-1;
					}
					e+=d*f;
					break;
				}
				else
				{
					d+=k[j[c]];
					f=i[b]-j[c];
					if(f>0)
					{
						f*=-1;
					}
					e+=k[j[c]]*f;
				}
			}
		}
		printf("%lld\n",e);
	}
	return 0;
}