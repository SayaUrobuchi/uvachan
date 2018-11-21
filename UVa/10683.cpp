#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,l[]={3600000,360000,60000,6000,1000,100,10,1};
	double j;
	char k[9];
	j=10000000;
	j/=8640000;
	while(scanf("%s",k)==1)
	{
		for(a=0,i=0;a<8;a++)
		{
			i+=l[a]*(k[a]-48);
		}
		i*=j;
		printf("%07d\n",i);
	}
	return 0;
}