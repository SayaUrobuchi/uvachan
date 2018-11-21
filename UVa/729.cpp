#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k;
char x[18];
int abcc()
{
	if(b==a)
	{
		printf("%s\n",x);
		return 0;
	}
	if(c>0)
	{
		x[b]=48;
		b++;
		c--;
		abcc();
		c++;
		b--;
	}
	if(a-c!=b)
	{
		x[b]=49;
		b++;
		abcc();
		b--;
	}
	return 0;
}
int main()
{
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d %d",&a,&b);
		c=a-b;
		x[a]='\0';
		b=0;
		abcc();
		printf("\n");
	}
	return 0;
}