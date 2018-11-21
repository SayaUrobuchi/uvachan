#include<stdio.h>
char x,y;
int a,b,c,d,e,f,g,h,i,j[2000],k[2000];
int abcc(int c)
{
	int p=0,q=0,z=0;
	k[d]=0;
	j[d]=0;
	while(scanf("%c",&x)==1)
	{
		if(x=='(')
		{
			if(p==1)
			{
				k[d]*=-1;
			}
			p=0;
			b+=k[d];
			d++;
			c=abcc(c);
			d--;
			if(j[d+1]==0)
			{
				if(z==1)
				{
					if(b==a)
					{
						c=1;
					}
				}
				else
				{
					z=1;
				}
			}
			q++;
			b-=k[d];
		}
		else if(x==')')
		{
			if(j[d]==0)
			{
				break;
			}
			if(q==2)
			{
				break;
			}
		}
		else if(x>47&&x<58)
		{
			j[d]=1;
			k[d]*=10;
			k[d]+=x-48;
		}
		else if(x=='-')
		{
			p=1;
		}
	}
	return c;
}
int main()
{
	while(scanf("%d",&a)==1)
	{
		while(scanf("%c",&x)==1)
		{
			if(x=='(')
			{
				b=0;
				c=0;
				d=0;
				e=abcc(c);
				if(e==0)
				{
					printf("no\n");
				}
				else
				{
					printf("yes\n");
				}
				break;
			}
		}
	}
	return 0;
}