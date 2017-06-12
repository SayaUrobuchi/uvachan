#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j[1000001];
bool k[1000001],x[1000001];
int main()
{
	k[2]=1;
	x[2]=1;
	for(a=1;a<1000001;a+=2)
	{
		k[a]=1;
	}
	for(a=3;a<333334;a+=2)
	{
		for(b=a*3,c=b-a;b<1000001;b+=c)
		{
			k[b]=0;
		}
	}
	for(a=3;a<1000001;a+=2)
	{
		if(k[a]==1)
		{
			for(b=a,c=0;b>0;b/=10)
			{
				c+=b%10;
			}
			x[a]=k[c];
		}
	}
	j[1]=0;
	for(a=2;a<1000001;a++)
	{
		j[a]=j[a-1]+x[a];
	}
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",j[b]-j[a]+x[a]);
	}
	return 0;
}