#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h;
	char i[25][25],j[25][25],k[25],p[25],x,s;
	s=0;
	scanf("%d",&g);
	for(a=0;a<20;a++)
	{
		i[0][a]='*';
	}
	i[0][a]='\0';
	for(a=0;a<20;a++)
	{
		j[0][a]=32;
	}
	j[0][a]='\0';
	strcpy(i[20],j[0]);
	k[0]=-1;
	k[21]=-1;
	s=0;
	scanf("%d%c",&h,&x);
	for(g;g>0;g--)
	{
		if(s)
		{
			printf("\n");
		}
		s=1;
		for(a=1;a<21;a++)
		{
			k[a]=-1;
			strcpy(i[a],j[0]);
			strcpy(j[a],j[0]);
		}
		printf("%s\n",i[0]);
		while(scanf("%d%c",&a,&x)==2)
		{
			if(x==10)
			{
				break;
			}
			scanf("%d",&b);
			b--;
			i[a][b]='O';
			if(b>k[a])
			{
				k[a]=b;
			}
		}
		for(b=1;b<21;b++)
		{
			strcpy(j[b],i[b]);
			printf("%s\n",j[b]);
		}
		printf("%s\n",i[0]);
		h--;
		for(h;h>0;h--)
		{
			for(b=1;b<21;b++)
			{
				p[b]=-1;
				if(k[b]==-1&&k[b-1]==-1&&k[b+1]==-1)
				{
					continue;
				}
				for(c=0,d=0;c<20;c++)
				{
					if(c>0)
					{
						if(i[b][c-1]=='O')
						{
							d++;
						}
						if(i[b-1][c-1]=='O')
						{
							d++;
						}
						if(i[b+1][c-1]=='O')
						{
							d++;
						}
					}
					if(c<19)
					{
						if(i[b][c+1]=='O')
						{
							d++;
						}
						if(i[b-1][c+1]=='O')
						{
							d++;
						}
						if(i[b+1][c+1]=='O')
						{
							d++;
						}
					}
					if(i[b-1][c]=='O')
					{
						d++;
					}
					if(i[b+1][c]=='O')
					{
						d++;
					}
					if(d<=1||d>=4)
					{
						j[b][c]=32;
					}
					if(d==3)
					{
						j[b][c]='O';
					}
					if(j[b][c]=='O')
					{
						p[b]=c;
					}
					d=0;
				}
			}
			for(b=1;b<21;b++)
			{
				printf("%s\n",j[b]);
				strcpy(i[b],j[b]);
				k[b]=p[b];
			}
			printf("%s\n",i[0]);
		}
		h=a;
	}
	return 0;
}
