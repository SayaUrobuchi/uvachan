#include<stdio.h>
#include<string.h>
char k[52][53],x;
int a,b,c,d,e,f,g,h,i,j,z;
int abcc(char y)
{
	if(y=='C')
	{
		return 0;
	}
	else if(y=='D')
	{
		return 13;
	}
	else if(y=='H')
	{
		return 26;
	}
	else
	{
		return 39;
	}
}
int bcaa(char y)
{
	if(y=='A')
	{
		return 1;
	}
	else if(y=='T')
	{
		return 10;
	}
	else if(y=='J')
	{
		return 11;
	}
	else if(y=='Q')
	{
		return 12;
	}
	else if(y=='K')
	{
		return 13;
	}
	else
	{
		return y-48;
	}
}
int main()
{
	while(scanf("%c",&x)==1)
	{
		g=0;
		if(x=='#')
		{
			scanf("%c",&x);
			break;
		}
		k[0][1]=bcaa(x);
		k[0][0]=1;
		scanf("%c",&x);
		k[0][1]+=abcc(x);
		scanf("%c",&x);
		for(a=1;a<52;a++)
		{
			scanf("%c",&x);
			k[a][1]=bcaa(x);
			scanf("%c",&x);
			k[a][1]+=abcc(x);
			k[a][0]=1;
			scanf("%c",&x);
		}
		for(a=1,i=52;a<i;a++)
		{
			z=a;
			if(a>2)
			{
				b=a-3;
				c=k[b][0];
				d=k[a][0];
				e=k[b][c];
				f=k[a][d];
				if(e%13==f%13)
				{
					k[b][0]++;
					k[b][c+1]=f;
					k[a][0]--;
					if(k[a][0]==0)
					{
						i--;
						for(a;a<i;a++)
						{
							d=k[a+1][0];
							k[a+1][d+1]='\0';
							strcpy(k[a],k[a+1]);
						}
					}
					a=z-4;
					if(a==-1)
					{
						a=0;
					}
					continue;
				}
				else if((e-1)/13==(f-1)/13)
				{
					k[b][0]++;
					k[b][c+1]=f;
					k[a][0]--;
					if(k[a][0]==0)
					{
						i--;
						for(a;a<i;a++)
						{
							d=k[a+1][0];
							k[a+1][d+1]='\0';
							strcpy(k[a],k[a+1]);
						}
					}
					a=z-4;
					if(a==-1)
					{
						a=0;
					}
					continue;
				}
			}
			b=a-1;
				c=k[b][0];
				d=k[a][0];
				e=k[b][c];
				f=k[a][d];
				if(e%13==f%13)
				{
					k[b][0]++;
					k[b][c+1]=f;
					k[a][0]--;
					if(k[a][0]==0)
					{
						i--;
						for(a;a<i;a++)
						{
							d=k[a+1][0];
							k[a+1][d+1]='\0';
							strcpy(k[a],k[a+1]);
						}
					}
					a=z-2;
					if(a==-1)
					{
						a=0;
					}
					continue;
				}
				else if((e-1)/13==(f-1)/13)
				{
					k[b][0]++;
					k[b][c+1]=f;
					k[a][0]--;
					if(k[a][0]==0)
					{
						i--;
						for(a;a<i;a++)
						{
							d=k[a+1][0];
							k[a+1][d+1]='\0';
							strcpy(k[a],k[a+1]);
						}
					}
					a=z-2;
					if(a==-1)
					{
						a=0;
					}
					continue;
				}
		}
		if(i>1)
		{
		printf("%d piles remaining:",i);
		for(a=0;a<i;a++)
		{
			printf(" %d",k[a][0]);
		}
		printf("\n");
		}
		else
		{
			printf("1 pile remaining: 52\n");
		}
	}
	return 0;
}