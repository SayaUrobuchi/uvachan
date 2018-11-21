#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[20],l[20];
	k[0]=1;
	l[0]=1;
	k[1]=2;
	l[1]=3;
	for(a=2;a<20;a++)
	{
		k[a]=k[a-1]*2;
		l[a]=l[a-1]*2;
	}
	while(scanf("%d%d",&a,&b)==2)
	{
		a%=l[b];
		if(!a)
		{
			printf("0\n");
			continue;
		}
		else if(a==1)
		{
			printf("%d\n",1%k[b]);
			continue;
		}
		for(a--,c=0,d=1,e=0;a>0;a--)
		{
			e=c+d;
			e%=k[b];
			c=d;
			d=e;
		}
		printf("%d\n",e);
	}
	return 0;
}