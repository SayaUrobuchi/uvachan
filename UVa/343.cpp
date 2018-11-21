#include<stdio.h>
#include<string.h>
int abcc(char z)
{
	if(z>64)
	{
		return z-55;
	}
	else
	{
		return z-48;
	}
}
int main()
{
	int a,b,c,d,e,f,g,h,i,j[37],k[37];
	char x[50],y[50],z[50],w[50];
	while(scanf("%s%s",&x,&y)==2)
	{
		strcpy(z,x);
		strcpy(w,y);
		g=strlen(x);
		for(b=0,c=0;b<g;b++)
		{
			x[b]=abcc(x[b]);
			if(x[b]>c)
			{
				c=x[b];
			}
		}
		if(c==0)
		{
			c++;
		}
		c++;
		h=strlen(y);
		for(b=0,d=0;b<h;b++)
		{
			y[b]=abcc(y[b]);
			if(y[b]>d)
			{
				d=y[b];
			}
		}
		if(d==0)
		{
			d++;
		}
		d++;
		for(e=c;e<37;e++)
		{
			for(a=g-1,f=1,j[e]=0;a>-1;a--,f*=e)
			{
				j[e]+=f*x[a];
			}
		}
		for(e=d,b=0;e<37&&b==0;e++)
		{
			for(a=h-1,f=1,i=0;a>-1;a--,f*=e)
			{
				i+=f*y[a];
			}
			for(f=c;f<37;f++)
			{
				if(i==j[f])
				{
					printf("%s (base %d) = %s (base %d)\n",z,f,w,e);
					b=1;
					break;
				}
			}
		}
		if(b==0)
		{
			printf("%s is not equal to %s in any base 2..36\n",z,w);
		}
	}
	return 0;
}