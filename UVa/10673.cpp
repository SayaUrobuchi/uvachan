#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	scanf("%d",&a);
	for(a;a>0;a--)
	{
		scanf("%d%d",&b,&c);
		if(b%c==0)
		{
			printf("0 %d\n",c);
		}
		else if(b<c)
		{
			printf("0 %d\n",b);
		}
		else
		{
			d=b/c;
			e=b%d;
			f=b/d;
			printf("%d %d\n",f-e,e);
		}
	}
	return 0;
}