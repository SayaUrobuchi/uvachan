#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d",&a);
	for(a;a>0;a--)
	{
		scanf("%d",&b);
		for(f=0;b>0;b--)
		{
			scanf("%d %d %d",&c,&d,&e);
			f+=c*e;
		}
		printf("%d\n",f);
	}
	return 0;
}