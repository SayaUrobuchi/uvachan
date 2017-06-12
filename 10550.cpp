#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	while(scanf("%d %d %d %d",&a,&b,&c,&d)==4)
	{
		if(a==0&&b==0&&c==0&&d==0)
		{
			break;
		}
		e=a-b;
		if(e<0)
		{
			e+=40;
		}
		i=c-b;
		if(i<0)
		{
			i+=40;
		}
		e+=i;
		i=c-d;
		if(i<0)
		{
			i+=40;
		}
		e+=i;
		e*=9;
		e+=1080;
		printf("%d\n",e);
	}
	return 0;
}