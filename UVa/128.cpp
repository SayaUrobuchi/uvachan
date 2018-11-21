#include<stdio.h>
#include<string.h>
int main()
{
	int a,c,d,f,g,h,j;
	unsigned long b;
	long long i;
	char x[1050],y,k[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	while(scanf("%c",&y)==1)
	{
		if(y==10)
		{
			printf("00 00\n");
			continue;
		}
		gets(x);
		a=strlen(x);
		if(a==0&&y=='#')
		{
			break;
		}
		for(a-=1,i=0,b=256,c=1;a>=0;a--)
		{
			b*=256;
			if(c==0)
			{
				c++;
			}
			else
			{
				c--;
				b%=34943;
			}
			i+=b*x[a];
		}
		b*=256;
		if(c!=0)
		{
			b%=34943;
		}
		i+=b*y;
		i%=34943;
		if(i==0)
		{
			printf("00 00\n");
		}
		else
		{
			j=34943-i;
			b=j%256;
			c=j/256;
			printf("%c%c %c%c\n",k[c/16],k[c%16],k[b/16],k[b%16]);
		}
	}
	return 0;
}