#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[173];
	k[0]=2;
	k[1]=3;
	for(a=5,c=2;a<1032;a+=2)
	{
		for(b=0;b<c;b++)
		{
			if(!(a%k[b]))
			{
				break;
			}
		}
		if(b==c)
		{
			k[c++]=a;
		}
	}
	while(scanf("%d",&a)==1)
	{
		for(i=0;a>0;a--)
		{
			scanf("%d",&b);
			if(b>3)
			{
				g=sqrt(b)+1;
				for(f=0;k[f]<g;f++)
				{
					if(!(b%k[f]))
					{
						b/=k[f];
						g=sqrt(b)+1;
						for(f;k[f]<g;f++)
						{
							if(!(b%k[f]))
							{
								break;
							}
						}
						if(k[f]>=g)
						{
							i++;
						}
						break;
					}
				}
			}
		}
		printf("%d\n",i);
	}
	return 0;
}