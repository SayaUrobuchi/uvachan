#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	char x;
	i=0;
	while(scanf("%c",&x)==1)
	{
		if(x==10)
		{
			continue;
		}
		if(x=='#')
		{
			if(i==0)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
			i=0;
			continue;
		}
		i*=2;
		i+=x-48;
		if(i>131070)
		{
			i%=131071;
		}
	}
	return 0;
}