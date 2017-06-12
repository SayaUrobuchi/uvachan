#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	char check;
	check = 0;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		if(check) printf("\n");
		check = 1;
		scanf("%d",&g);
		scanf("%d%d",&a,&b);
		a-=b;
		i=a;
		for(g--;g>0;g--)
		{
			scanf("%d%d",&a,&b);
			a-=b;
			if(a!=i)
			{
				i=-1;
			}
		}
		if(i==-1)
		{
			printf("no\n");
		}
		else
		{
			printf("yes\n");
		}
	}
	return 0;
}
