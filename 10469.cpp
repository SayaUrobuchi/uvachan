#include<stdio.h>
int main()
{
	unsigned int a,b;
	while(scanf("%d %d",&a,&b)==2)
	{
		printf("%d\n",a^b);
	}
	return 0;
}