#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h[11],i[11],j[11],p,q[11];
	char k[11][15],x[15],s;
	s=0;
	while(scanf("%d",&a)==1)
	{
		if(s)
		{
			printf("\n");
		}
		s=1;
		for(b=0;b<a;b++)
		{
			scanf("%s",&k[b]);
			h[b]=strlen(k[b]);
			j[b]=0;
		}
		for(b=0;b<a;b++)
		{
			scanf("%s",&x);
			d=strlen(x);
			for(c=0;c<a;c++)
			{
				if(d==h[c])
				{
					if(strcmp(k[c],x)==0)
					{
						break;
					}
				}
			}
			scanf("%d%d",&i[c],&d);
			if(d==0)
			{
				q[c]=0;
				continue;
			}
			q[c]=i[c]-i[c]%d;
			p=i[c]/d;
			for(e=0;e<d;e++)
			{
				scanf("%s",&x);
				f=strlen(x);
				for(g=0;g<a;g++)
				{
					if(f==h[g])
					{
						if(strcmp(k[g],x)==0)
						{
							break;
						}
					}
				}
				j[g]+=p;
			}
		}
		for(b=0;b<a;b++)
		{
			printf("%s %d\n",k[b],j[b]-q[b]);
		}
	}
	return 0;
}