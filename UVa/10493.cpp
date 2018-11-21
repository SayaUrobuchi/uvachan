#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a&&!b)
		{
			break;
		}
		if(b==1)
		{
			if(a==1)
			{
				printf("1 1 Multiple\n");
			}
			else
			{
				printf("%d 1 1\n",a);
			}
		}
		else
		{
			c=b-a;
			if(c<0)
			{
				printf("%d %d Impossible\n",a,b);
			}
			else
			{
				d=a-1;
				if(!d)
				{
					printf("%d %d Impossible\n",a,b);
				}
				else if(c%d)
				{
					printf("%d %d Impossible\n",a,b);
				}
				else
				{
					c/=d;
					d=a*c+a+1;
					printf("%d %d %d\n",a,b,d);
				}
			}
		}
	}
	return 0;
}