#include<stdio.h>
#include<string.h>
int main()
{
	char j[20];
	int a,b,c,d,e,f[2000],g[2000][2],h,i[2000],k[2000],y[2000],z;
	gets(j);
	sscanf(j,"%d",&h);
	gets(j);
	for(h;h>0;h--)
	{
		c=0;
		b=0;
		e=0;
		while(gets(j)!=NULL)
		{
			if(strlen(j)==0)
			{
				break;
			}
			sscanf(j,"%d",&a);
			if(c==0)
			{
				k[0]=a;
				g[0][0]=a;
				g[0][1]=-1;
				f[0]=0;
				b++;
				c++;
			}
			else
			{
				if(a>k[c-1])
				{
					k[c]=a;
					g[b][0]=a;
					g[b][1]=f[c-1];
					f[c]=b;
					b++;
					c++;
				}
				else
				{
					for(d=0;d<c;d++)
					{
						if(k[d]>a)
						{
							k[d]=a;
							g[b][0]=a;
							if(d>0)
							{
								g[b][1]=f[d-1];
							}
							else
							{
								g[b][1]=-1;
							}
							f[d]=b;
							b++;
							break;
						}
					}
				}
			}
		}
		if(z==1)
		{
			printf("\n");
		}
		z=1;
		printf("Max hits: %d\n",c);
		for(a=k[c-1],b=f[c-1],d=0;d<c;d++)
		{
			i[d]=a;
			b=g[b][1];
			if(b!=-1)
			{
				a=g[b][0];
			}
		}
		for(d-=1;d>=0;d--)
		{
			printf("%d\n",i[d]);
		}
	}
	return 0;
}