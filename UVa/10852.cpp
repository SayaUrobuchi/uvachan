#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d",&a);
		b=a/2+1;
		if(b%2==0)
		{
			b++;
		}
		for(b;;b+=2)
		{
			c=sqrt(b)+1;
			for(d=3;d<c;d+=2)
			{
				if(b%d==0)
				{
					break;
				}
			}
			if(d>=c)
			{
				printf("%d\n",b);
				break;
			}
		}
	}
	return 0;
}