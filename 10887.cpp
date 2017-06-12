#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	char k[12];
	scanf("%d",&e);
	e++;
	for(d=1;d<e;d++)
	{
		scanf("%d%d",&a,&b);
		printf("Case %d: %d\n",d,a*b);
		for(a+=b;a>0;a--)
		{
			scanf("%s",&k);
		}
	}
}