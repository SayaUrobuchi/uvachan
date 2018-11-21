#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[77];
	k[1]=1;
	k[2]=2;
	k[3]=2;
	for(a=4;a<77;a++)
	{
		k[a]=k[a-2]+k[a-3];
	}
	while(scanf("%d",&a)==1)
	{
		printf("%d\n",k[a]);
	}
	return 0;
}