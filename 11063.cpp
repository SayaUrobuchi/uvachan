#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j[100];
	bool k[20001];
	h=0;
	while(scanf("%d",&a)==1)
	{
		i=0;
		scanf("%d",&j[0]);
		if(j[0]<1)
		{
			i=1;
		}
		for(b=1;b<a;b++)
		{
			scanf("%d",&j[b]);
			if(j[b]<1)
			{
				i=1;
			}
			if(j[b]<=j[b-1])
			{
				i=1;
			}
		}
		if(i==1)
		{
			printf("Case #%d: It is not a B2-Sequence.\n\n",++h);
			continue;
		}
		for(b=0;b<20001;b++)
		{
			k[b]=0;
		}
		for(b=0;b<a;b++)
		{
			d=j[b];
			for(c=b;c<a;c++)
			{
				e=j[c];
				if(k[d+e]==1)
				{
					i=1;
					break;
				}
				k[d+e]=1;
			}
			if(i==1)
			{
				printf("Case #%d: It is not a B2-Sequence.\n\n",++h);
				break;
			}
		}
		if(i==0)
		{
			printf("Case #%d: It is a B2-Sequence.\n\n",++h);
		}
	}
	return 0;
}