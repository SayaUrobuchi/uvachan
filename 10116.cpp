#include<stdio.h>
int main()
{
	int a,b,c,d,i;
	char k[10][11],x;
	while(scanf("%d%d%d%c",&a,&b,&c,&x)==4)
	{
		if(a==0&&b==0&&c==0)
		{
			break;
		}
		for(d=0;d<a;d++)
		{
			gets(k[d]);
		}
		for(d=c-1,c=0,i=0;;i++)
		{
			if(d<0||c<0||c==a||d==b)
			{
				printf("%d step(s) to exit\n",i);
				break;
			}
			if(k[c][d]=='N')
			{
				k[c][d]=i;
				c--;
			}
			else if(k[c][d]=='S')
			{
				k[c][d]=i;
				c++;
			}
			else if(k[c][d]=='E')
			{
				k[c][d]=i;
				d++;
			}
			else if(k[c][d]=='W')
			{
				k[c][d]=i;
				d--;
			}
			else
			{
				printf("%d step(s) before a loop of %d step(s)\n",k[c][d],i-k[c][d]);
				break;
			}
		}
	}
	return 0;
}