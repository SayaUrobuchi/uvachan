#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d",&a);
	for(a;a>0;a--)
	{
		scanf("%d %d",&b,&c);
		for(c;c>0;c--)
		{
			e=1;
			d=1;
			for(d;d!=0;d+=e)
			{
				f=d;
				for(f;f>0;f--)
				{
					printf("%d",d);
				}
				printf("\n");
			    if(d==b)
				{
					e=-1;
				}
			}
			printf("\n");
		}
	}
	return 0;
}
