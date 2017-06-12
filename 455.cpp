#include<stdio.h>
#include<string.h>
int main()
{
	char k[85],x,s;
	int a,b,c,d,e,f,g,h,i,j;
	s=0;
	scanf("%d%c",&h,&x);
	for(h;h>0;h--)
	{
		if(s)
		{
			printf("\n");
		}
		s=1;
		gets(k);
		gets(k);
		a=strlen(k);
		for(b=1;b<=a;b++)
		{
			if(a%b==0)
			{
				for(i=0;i<b;i++)
				{
					for(c=i+b;c<a;c+=b)
					{
						if(k[c]!=k[i])
						{
							break;
						}
					}
					if(c<a)
					{
						break;
					}
				}
				if(c>=a)
				{
					printf("%d\n",b);
					break;
				}
			}
		}
	}
	return 0;
}