#include<stdio.h>
#include<math.h>
int abcc(int x,int y)
{
	int w,z;
	for(;;)
	{
		if(x>y)
		{
			x%=y;
			if(x<2)
			{
				z=x;
				w=y;
				break;
			}
		}
		else
		{
			y%=x;
			if(y<2)
			{
				z=y;
				w=x;
				break;
			}
		}
	}
	if(z==1)
	{
		return 1;
	}
	else
	{
		return w;
	}
}
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[1000];
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		if(a<0)
		{
			b=1;
			a*=-1;
		}
		c=0;
		if(a%2==0)
		{
			k[0]=0;
			for(;;)
			{
				a/=2;
				k[0]++;
				if(a%2!=0)
				{
					break;
				}
			}
			c++;
		}
		i=sqrt(a);
		for(d=3;d<=i;d+=2)
		{
			if(a%d==0)
			{
				k[c]=0;
				for(;;)
				{
					a/=d;
					k[c]++;
					if(a%d!=0)
					{
						break;
					}
				}
				c++;
			}
			if(a==1)
			{
				break;
			}
		}
		if(a>1)
		{
			k[c]=1;
			c++;
		}
		c--;
		if(c==0)
		{
			c=k[0];
			if(b==1)
			{
				if(c%2==0)
				{
					for(;;)
					{
						c/=2;
						if(c%2==1)
						{
							break;
						}
					}
				}
			}
			printf("%d\n",c);
		}
		else
		{
		//printf("ccc %d\n",c);
			for(d=0;d<c;d++)
			{
				e=abcc(k[d],k[d+1]);
				if(e==1)
				{
					break;
				}
			}
			if(b==1&&e%2==0)
			{
				for(;;)
				{
					e/=2;
					if(e%2==1)
					{
						break;
					}
				}
			}
			printf("%d\n",e);
		}
		b=0;
	}
	return 0;
}