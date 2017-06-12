#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	char x,y[300];
	bool z[480];
	g=0;
	while(scanf("%d",&h)==1)
	{
		i=0;
		j=0;
		k=0;
		for(a=0;a<480;a++)
		{
			z[a]=0;
		}
		for(h;h>0;h--)
		{
			scanf("%d%c%d",&a,&x,&b);
			a-=10;
			a*=60;
			a+=b;
			scanf("%d%c%d",&c,&x,&d);
			c-=10;
			c*=60;
			c+=d;
			gets(y);
			for(b=a;b<c;b++)
			{
				z[b]=1;
			}
		}
		for(a=0;a<480;a++)
		{
			if(z[a]==0)
			{
				b=a;
				for(a;z[a]==0&&a<480;a++)
				{
				}
				c=a-b;
				if(c>j)
				{
					j=c;
					k=b;
				}
			}
		}
		/*for(h;h>0;h--)
		{
			scanf("%d%c%d",&a,&x,&b);
			a-=10;
			a*=60;
			a+=b;
			b=a-i;
			if(b>j)
			{
				j=b;
				k=i;
			}
			scanf("%d%c%d",&a,&x,&b);
			i=(a-10)*60+b;
			gets(y);
		}
		a=480-i;
		if(a>j)
		{
			j=a;
			k=i;
		}*/
		printf("Day #%d: the longest nap starts at %d:%02d and will last for ",++g,k/60+10,k%60);
		if(j>59)
		{
			printf("%d hours and %d minutes.\n",j/60,j%60);
		}
		else
		{
			printf("%d minutes.\n",j);
		}
	}
	return 0;
}