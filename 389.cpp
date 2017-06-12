#include<stdio.h>
int abcc(char y)
{
	if(y>64)
	{
		return y-55;
	}
	return y-48;
}
int bcaa(int y)
{
	if(y>9)
	{
		return y+55;
	}
	return y+48;
}
int main()
{
	int a,b,c,d,f,g,h,j;
	unsigned long long e,i;
	char k[100],x;
	while(scanf("%c",&x)==1)
	{
		if(x!=32)
		{
			a=0;
			k[a]=x;
			for(a=1;a<100;a++)
			{
				scanf("%c",&k[a]);
				if(k[a]==32)
				{
					break;
				}
			}
			scanf("%d %d",&b,&c);
			while(1)
			{
				scanf("%c",&x);
				if(x==10)
				{
					break;
				}
			}
			for(a-=1,e=1,i=0;a>=0;a--,e*=b)
			{
				d=abcc(k[a]);
				i+=d*e;
			}
			if(i<2)
			{
				printf("%7d\n",i);
				continue;
			}
			if(c==10)
			{
				if(i>9999999)
				{
					printf("  ERROR\n");
					continue;
				}
				printf("%7lld\n",i);
				continue;
			}
			for(a=0;i>0;i/=c,a++)
			{
				k[a]=bcaa(i%c);
				if(a>6)
				{
					break;
				}
			}
			if(i>0)
			{
				printf("  ERROR\n");
				continue;
			}
			for(a;a<7;a++)
			{
				k[a]=32;
			}
			for(a-=1;a>=0;a--)
			{
				printf("%c",k[a]);
			}
			printf("\n");
		}
	}
	return 0;
}