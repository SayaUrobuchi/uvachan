#include<stdio.h>
int k[1000][1000];
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d%d",&a,&b);
		for(c=0;c<a;c++)
		{
			for(d=0;d<b;d++)
			{
				scanf("%d",&k[c][d]);
			}
		}
		for(c=1;c<a;c++)
		{
			k[c][0]+=k[c-1][0];
		}
		for(c=1;c<b;c++)
		{
			k[0][c]+=k[0][c-1];
		}
		for(c=1;c<a;c++)
		{
			for(d=1;d<b;d++)
			{
				if(k[c-1][d]>k[c][d-1])
				{
					k[c][d]+=k[c][d-1];
				}
				else
				{
					k[c][d]+=k[c-1][d];
				}
			}
		}
		printf("%d\n",k[a-1][b-1]);
	}
	return 0;
}