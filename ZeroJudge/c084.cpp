#include<stdio.h>
#include<string.h>
char k[1000][1000],l[1000][10];
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a&&!b)
		{
			break;
		}
		for(c=0;c<b;c++)
		{
			for(d=0;d<10;d++)
			{
				l[c][d]=1;
			}
		}
		a%=b;
		if(!a)
		{
			printf(".\nThis expansion terminates.\n\n");
		}
		else
		{
			printf(".");
			d=1;
			while(1)
			{
				a*=10;
				c=a/b;
				a%=b;
				if(l[a][c])
				{
					k[a][c]=d;
					l[a][c]=0;
					if(!(d%50))
					{
						printf("\n");
					}
					printf("%d",c);
					d++;
					if(!a)
					{
						printf("\nThis expansion terminates.\n\n");
						break;
					}
				}
				else
				{
					printf("\nThe last %d digits repeat forever.\n\n",d-k[a][c]);
					break;
				}
			}
		}
	}
	return 0;
}
