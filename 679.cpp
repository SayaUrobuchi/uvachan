#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[20],l;
	for(b=1,k[0]=1;b<20;b++)
	{
		k[b]=k[b-1]*2;
	}
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d%d",&a,&b);
		i=k[a-1];
		for(c=a-2;b>1;c--)
		{
			if(!(b%2))
			{
				i+=k[c];
			}
			b++;
			b/=2;
		}
		printf("%d\n",i);
	}
	return 0;
}