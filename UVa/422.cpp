#include<stdio.h>
#include<string.h>
int a,b,c,d,e,f,g,h,i,j;
char k[105][105],x,y[105];
int abcc()
{
	int p,q,z;
	if(c>=b)
	{
		for(p=c-1,q=d,z=1;z<=b;z++,p--)
		{
			if(k[p][q]!=y[z])
			{
				break;
			}
		}
		if(z>b)
		{
			i++;
			j++;
			printf("%d,%d %d,%d\n",i,j,i-b,j);
			return 1;
		}
		if(d>=b)
		{
			for(p=c-1,q=d-1,z=1;z<=b;z++,p--,q--)
			{
				if(k[p][q]!=y[z])
				{
					break;
				}
			}
			if(z>b)
			{
				i++;
				j++;
				printf("%d,%d %d,%d\n",i,j,i-b,j-b);
				return 1;
			}
		}
		if(d+b<a)
		{
			for(p=c-1,q=d+1,z=1;z<=b;z++,p--,q++)
			{
				if(k[p][q]!=y[z])
				{
					break;
				}
			}
			if(z>b)
			{
				i++;
				j++;
				printf("%d,%d %d,%d\n",i,j,i-b,j+b);
				return 1;
			}
		}
	}
	if(d>=b)
	{
		for(p=c,q=d-1,z=1;z<=b;z++,q--)
		{
			if(k[p][q]!=y[z])
			{
				break;
			}
		}
		if(z>b)
		{
			i++;
			j++;
			printf("%d,%d %d,%d\n",i,j,i,j-b);
			return 1;
		}
	}
	if(d+b<a)
	{
		for(p=c,q=d+1,z=1;z<=b;z++,q++)
		{
			if(k[p][q]!=y[z])
			{
				break;
			}
		}
		if(z>b)
		{
			i++;
			j++;
			printf("%d,%d %d,%d\n",i,j,i,j+b);
			return 1;
		}
	}
	if(c+b<a)
	{
		for(p=c+1,q=d,z=1;z<=b;z++,p++)
		{
			if(k[p][q]!=y[z])
			{
				break;
			}
		}
		if(z>b)
		{
			i++;
			j++;
			printf("%d,%d %d,%d\n",i,j,i+b,j);
			return 1;
		}
		if(d>=b)
		{
			for(p=c+1,q=d-1,z=1;z<=b;z++,p++,q--)
			{
				if(k[p][q]!=y[z])
				{
					break;
				}
			}
			if(z>b)
			{
				i++;
				j++;
				printf("%d,%d %d,%d\n",i,j,i+b,j-b);
				return 1;
			}
		}
		if(d+b<a)
		{
			for(p=c+1,q=d+1,z=1;z<=b;z++,p++,q++)
			{
				if(k[p][q]!=y[z])
				{
					break;
				}
			}
			if(z>b)
			{
				i++;
				j++;
				printf("%d,%d %d,%d\n",i,j,i+b,j+b);
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d%c",&a,&x);
	for(b=0;b<a;b++)
	{
		gets(k[b]);
	}
	while(1)
	{
		gets(y);
		if(strcmp(y,"0")==0)
		{
			break;
		}
		b=strlen(y);
		b--;
		for(c=0,h=0;c<a;c++)
		{
			for(d=0;d<a;d++)
			{
				if(y[0]==k[c][d])
				{
					i=c;
					j=d;
					h=abcc();
					if(h==1)
					{
						break;
					}
				}
			}
			if(h==1)
			{
				break;
			}
		}
		if(h!=1)
		{
			printf("Not found\n");
		}
	}
	return 0;
}