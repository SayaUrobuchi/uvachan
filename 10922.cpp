#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d;
	char k[1005],x;
	while(gets(k))
	{
		a=strlen(k);
		if(a==1)
		{
			if(k[0]=='0')
			{
				break;
			}
		}
		for(b=0,c=0;b<a;b++)
		{
			c+=k[b]-48;
		}
		if(c%9==0)
		{
			b=1;
			if(c!=9)
			{
				for(;;)
				{
					for(d=0;;)
					{
						d+=c%10;
						c/=10;
						if(c<10)
						{
							d+=c%10;
							break;
						}
					}
					if(d%9==0)
					{
						b++;
						c=d;
						if(d==9)
						{
							break;
						}
						continue;
					}
					else
					{
						break;
					}
				}
			}
			printf("%s is a multiple of 9 and has 9-degree %d.\n",k,b);
		}
		else
		{
			printf("%s is not a multiple of 9.\n",k);
		}
	}
	return 0;
}