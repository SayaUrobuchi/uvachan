#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	char l[21],w[21],x[21],y[1000],z[1000];
	h=0;
	while(scanf("%d%d%d",&a,&b,&c)==3)
	{
		if(!a&&!b&&!c)
		{
			break;
		}
		for(d=0;d<a;d++)
		{
			w[d]='.';
			l[d]='*';
		}
		w[d]=0;
		l[d]=0;
		for(d=0;d<b;d++)
		{
			x[d]='*';
		}
		x[d]=0;
		strcpy(y,x);
		strcpy(z,x);
		for(d=0;d<c;d++)
		{
			strcat(y,l);
			strcat(z,w);
			strcat(y,x);
			strcat(z,x);
		}
		printf("Case %d:\n",++h);
		for(d=0;d<b;d++)
		{
			printf("%s\n",y);
		}
		for(d=0;d<c;d++)
		{
			for(e=0;e<a;e++)
			{
				printf("%s\n",z);
			}
			for(e=0;e<b;e++)
			{
				printf("%s\n",y);
			}
		}
		printf("\n");
	}
	return 0;
}