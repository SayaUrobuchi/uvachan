#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	while(scanf("%d",&d)==1)
	{
		e=d;
		a=1;
		b=1;
		c=1;
		for(d;d>1;d--)
		{
			if(a==1&&c==1)
			{
				b++;
				c*=-1;
			}
			else if(b==1&&c==-1)
			{
				a++;
				c*=-1;
			}
			else
			{
				b+=c;
				a-=c;
			}
		}
		printf("TERM %d IS %d/%d\n",e,a,b);
	}
	return 0;
}