#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	while(scanf("%d %d",&a,&b)==2)
	{
		c=a;
		e=0;
		for(;;)
		{
			e+=a%b;
			//printf("%d\n",e);
			a/=b;
			a+=e/b;
			e%=b;
			if(a==0)
			{
				break;
			}
			c+=a;
		}
		printf("%d\n",c);
	}
	return 0;
}