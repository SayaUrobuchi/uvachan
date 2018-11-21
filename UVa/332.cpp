#include<stdio.h>
#include<math.h>
#include<string.h>
int abcc(int p,int q)
{
	int y;
	while(q>1)
	{
		p%=q;
		y=p;
		p=q;
		q=y;
	}
	if(q)
	{
		return 1;
	}
	else
	{
		return p;
	}
}
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	char x[15];
	h=0;
	while(scanf("%d",&a)==1)
	{
		if(a==-1)
		{
			break;
		}
		gets(x);
		b=strlen(x);
		for(c=3,d=0;c<b;c++)
		{
			d*=10;
			d+=x[c]-48;
		}
		if(a==0)
		{
			b-=3;
			c=pow(10,b);
			e=abcc(c,d);
			c/=e;
			d/=e;
			printf("Case %d: %d/%d\n",++h,d,c);
			continue;
		}
		c=d/pow(10,a);
		d-=c;
		b-=3;
		b-=a;
		c=pow(10,a+b)-pow(10,b);
		e=abcc(c,d);
		c/=e;
		d/=e;
		printf("Case %d: %d/%d\n",++h,d,c);
	}
	return 0;
}