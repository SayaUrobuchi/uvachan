#include<stdio.h>
#include<string.h>
char k[1000000],x;
int a,b,c,d,e,f,g,h,i,j;
int main()
{
	while(gets(k))
	{
		if(strcmp(k,".")==0)
		{
			break;
		}
		a=strlen(k);
		for(b=1;b<=d;b++)
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
					printf("%d\n",a/b);
					break;
				}
			}
		}
	}
	return 0;
}