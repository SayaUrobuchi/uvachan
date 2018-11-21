#include<stdio.h>
int main()
{
	int a,b,c,d,g,h,i,j;
	long long e,f;
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		scanf("%d%d",&b,&c);
		for(d=0,e=0,f=0,g=-1;;d++)
		{
			e*=e;
			e%=a;
			e*=b;
			e+=c;
			e%=a;
			f*=f;
			f%=a;
			f*=b;
			f+=c;
			f%=a;
			f*=f;
			f%=a;
			f*=b;
			f+=c;
			f%=a;
			if(e==f)
			{
				if(g==-1)
				{
					g=d;
				}
				else
				{
					printf("%d\n",a-d+g);
					break;
				}
			}
		}
	}
	return 0;
}