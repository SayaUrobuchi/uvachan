#include<stdio.h>
int main()
{
	int a,c,d,e,f,g,h;
	unsigned long long b;
	while(scanf("%d",&a)==1)
	{
		b=1;
		while(1)
		{
			b*=9;
			if(a<=b)
			{
				printf("Stan wins.\n");
				break;
			}
			b*=2;
			if(a<=b)
			{
				printf("Ollie wins.\n");
				break;
			}
		}
	}
	return 0;
}
