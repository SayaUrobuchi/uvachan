#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[31];
	k[0]=1;
	for(a=1;a<31;a++)
	{
		k[a++]=0;
		k[a]=k[a-2];
		for(b=a-2;b>-1;b-=2)
		{
			k[a]+=k[b]*2;
		}
	}
	while(scanf("%d",&a)==1)
	{
		if(a==-1)
		{
			break;
		}
		printf("%d\n",k[a]);
	}
	return 0;
}