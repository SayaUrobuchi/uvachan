#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i[13];
	char j[13][4],k[13][4],x;
	while(scanf("%c",&j[12][0])==1)
	{
		if(j[12][0]=='#')
		{
			scanf("%c",&x);
			break;
		}
		scanf("%c%c",&k[12][0],&x);
		for(a=0,b=11;a<4;a++)
		{
			for(b;b>=0;b--)
			{
				i[b]=-1;
				scanf("%c%c%c",&j[b][a],&k[b][a],&x);
			}
			if(x!=10)
			{
				for(;;)
				{
					scanf("%c",&x);
					if(x==10)
					{
						break;
					}
				}
			}
			b=12;
		}
		a=1;
		i[12]++;
		x=j[12][0];
		for(;;)
		{
			printf("%d\n", b);
			if(x=='A')
			{
				x=0;
			}
			else if(x=='T')
			{
				x=9;
			}
			else if(x=='J')
			{
				x=10;
			}
			else if(x=='Q')
			{
				x=11;
			}
			else if(x=='K')
			{
				x=12;
			}
			else
			{
				x-=49;
			}
			if(i[x]==3)
			{
				printf("%02d,%c%c\n",a,j[b][i[b]],k[b][i[b]]);
				break;
			}
			b=x;
			i[x]++;
			x=j[x][i[x]];
			a++;
		}
	}
	return 0;
}
