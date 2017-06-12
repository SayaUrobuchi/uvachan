#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[5];
char l[5];
int abcc(int p,int q)
{
	int w;
	if(p==5)
	{
		if(q==23)
		{
			return 1;
		}
		return 0;
	}
	for(w=0;w<5;w++)
	{
		if(l[w])
		{
			l[w]=0;
			if(abcc(p+1,q+k[w]))
			{
				l[w]=1;
				return 1;
			}
			if(abcc(p+1,q-k[w]))
			{
				l[w]=1;
				return 1;
			}
			if(abcc(p+1,q*k[w]))
			{
				l[w]=1;
				return 1;
			}
			l[w]=1;
		}
	}
	return 0;
}
int main()
{
	for(a=0;a<5;a++)
	{
		l[a]=1;
	}
	while(scanf("%d",&k[0])==1)
	{
		for(a=1,b=0;a<5;a++)
		{
			scanf("%d",&k[a]);
			if(k[a])
			{
				b=1;
			}
		}
		if(!b&&!k[0])
		{
			break;
		}
		for(a=0,b=0;a<5;a++)
		{
			l[a]=0;
			b=abcc(1,k[a]);
			l[a]=1;
			if(b)
			{
				break;
			}
		}
		if(b)
		{
			printf("Possible\n");
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}