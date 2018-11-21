#include<stdio.h>
int a,b,c,d,e,f,g,h[16],i,j[17],k[10];
int abcc()
{
	int x,y,z;
	for(x=c;x<=a;x+=2)
	{
		if(j[x]==0)
		{
			d=x+b;
			for(e=0;e<10;e++)
			{
				if(d==k[e])
				{
					//printf("%d %d\n",x,b);
					if(i==a-1)
					{
						x++;
						for(e=0;e<10;e++)
						{
							if(x==k[e])
							{
								break;
							}
						}
						if(e==10)
						{
							break;
						}
						x--;
						printf("1");
						for(y=1;y<i;y++)
						{
							printf(" %d",h[y]);
						}
						printf(" %d\n",x);
					}
					y=c;
					if(c==2)
					{
						c=3;
					}
					else
					{
						c=2;
					}
					z=b;
					j[x]=1;
					b=x;
					h[i]=x;
					i++;
					abcc();
					i--;
					b=z;
					j[x]=0;
					c=y;
					break;
				}
				else if(d<k[e])
				{
					break;
				}
			}
		}
	}
	return 0;
}
int main()
{
	freopen("1.txt", "w", stdout);
	g=0;
	k[0]=3;
	for(a=5,b=1;a<32;a+=2)
	{
		for(c=0;c<b;c++)
		{
			if(a%k[c]==0)
			{
				break;
			}
		}
		if(c==b)
		{
			k[b]=a;
			b++;
		}
	}
	f=0;
	while(scanf("%d",&a)==1)
	{
		f++;
		for(b=2;b<=a;b++)
		{
			j[b]=0;
		}
		j[1]=1;
		i=1;
		h[0]=1;
		c=2;
		b=1;
		if(g==1)
		{
			printf("\n");
		}
		g=1;
		printf("Case %d:\n",f);
		abcc();
	}
	return 0;
}
