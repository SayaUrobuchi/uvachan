#include<stdio.h>
int abcc()
{
	int w,x,y,z;
	scanf("%d%d%d%d",&w,&x,&y,&z);
	if(w==0)
	{
		w=abcc();
	}
	if(y==0)
	{
		y=abcc();
	}
	if(w==-1||y==-1)
	{
		return -1;
	}
	else if(w*x==y*z)
	{
		return w+y;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int g,h;
	char check;
	check = 0;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		if(check) printf("\n");
		check = 1;
		g=abcc();
		if(g==-1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
