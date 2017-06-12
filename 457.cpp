#include<stdio.h>
int abcc(int p)
{
	if(p==0)
	{
		return 32;
	}
	if(p==1)
	{
		return '.';
	}
	if(p==2)
	{
		return 'x';
	}
	else
	{
		return 'W';
	}
}
int main()
{
	int a,b,c,d,e,f,g,h,i,j,x[9],y[40],z[40];
	char k[41],s;
	s=0;
	k[40]='\0';
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		if(s)
		{
			printf("\n");
		}
		s=1;
		for(a=0;a<10;a++)
		{
			scanf("%d",&x[a]);
		}
		for(a=0;a<40;a++)
		{
			y[a]=0;
			k[a]=32;
		}
		y[19]=1;
		k[19]='.';
		printf("%s\n",k);
		for(g=1;g<50;g++)
		{
			z[0]=y[0]+y[1];
			z[0]=x[z[0]];
			k[0]=abcc(z[0]);
			for(a=1;a<39;a++)
			{
				z[a]=y[a-1]+y[a]+y[a+1];
				z[a]=x[z[a]];
				k[a]=abcc(z[a]);
			}
			z[a]=y[38]+y[39];
			z[a]=x[z[a]];
			k[a]=abcc(z[a]);
			printf("%s\n",k);
			for(a=0;a<40;a++)
			{
				y[a]=z[a];
			}
		}
	}
	return 0;
}