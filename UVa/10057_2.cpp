#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[65536];
int main()
{
	while(scanf("%d",&a)==1)
	{
		for(b=0;b<65536;b++)
		{
			k[b]=0;
		}
		for(b=0;b<a;b++)
		{
			scanf("%d",&c);
			k[c]++;
		}
		for(b=1;b<65536;b++)
		{
			k[b]+=k[b-1];
		}
		if(a%2)
		{
			a++;
			a/=2;
			i=0;
			j=65535;
			while(1)
			{
				b=i+j;
				b/=2;
				if(k[b]==a)
				{
					break;
				}
				else if(k[b]>a)
				{
					j=b-1;
					if(i>j)
					{
						break;
					}
				}
				else
				{
					i=b+1;
					if(i>j)
					{
						b++;
						break;
					}
				}
			}
			for(d=b-1;d>-1;d--)
			{
				if(k[d]!=k[b])
				{
					break;
				}
			}
			b=d+1;
			if(b)
			{
				printf("%d %d %d\n",b,k[b]-k[b-1],1);
			}
			else
			{
				printf("%d %d %d\n",0,k[0],1);
			}
		}
		else
		{
			a/=2;
			i=0;
			j=65535;
			while(1)
			{
				b=i+j;
				b/=2;
				if(k[b]==a)
				{
					break;
				}
				else if(k[b]>a)
				{
					j=b-1;
					if(i>j)
					{
						break;
					}
				}
				else
				{
					i=b+1;
					if(i>j)
					{
						b++;
						break;
					}
				}
			}
			for(d=b-1;d>-1;d--)
			{
				if(k[d]!=k[b])
				{
					break;
				}
			}
			for(c=b+1;c<65536;c++)
			{
				if(k[c]!=k[b])
				{
					break;
				}
			}
			b=d+1;
			if(k[b]==a)
			{
				if(b)
				{
					printf("%d %d %d\n",b,k[c]-k[b-1],c-b+1);
				}
				else
				{
					printf("%d %d %d\n",b,k[c],c-b+1);
				}
			}
			else
			{
				if(b)
				{
					printf("%d %d %d\n",b,k[b]-k[b-1],1);
				}
				else
				{
					printf("%d %d %d\n",b,k[b],1);
				}
			}
		}
	}
	return 0;
}