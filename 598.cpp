#include<stdio.h>
#include<string.h>
int a,b,c,d,e,f,g,h;
char k[12][31],x,y[31],q[12][31];
bool z[12];
int abcc(int p)
{
	int r;
	if(c>b)
	{
		printf("%s",q[0]);
		for(r=1;r<c;r++)
		{
			printf(", %s",q[r]);
		}
		printf("\n");
		return 0;
	}
	for(p;p<d;p++)
	{
		strcpy(q[c],k[p]);
		c++;
		d++;
		abcc(p+1);
		d--;
		c--;
	}
	return 0;
}
int main()
{
	int s;
	s=0;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		if(s)
		{
			printf("\n");
		}
		s=1;
		while(scanf("%c",&x)==1)
		{
			if(x=='*')
			{
				scanf("%c",&x);
				a=0;
				while(scanf("%c",&x)==1)
				{
					if(x==10)
					{
						break;
					}
					gets(y);
					k[a][0]=x;
					k[a][1]='\0';
					strcpy(k[a],strcat(k[a],y));
					z[a]=0;
					a++;
				}
				for(b=0;b<a;b++)
				{
					printf("Size %d\n",b+1);
					c=0;
					d=a-b;
					abcc(0);
					printf("\n");
				}
				break;
			}
			else if(x>47&&x<58)
			{
				d=x-48;
				while(scanf("%c",&x)==1)
				{
					if(x==10)
					{
						a=0;
						while(scanf("%c",&x)==1)
						{
							if(x==10)
							{
								break;
							}
							gets(y);
							k[a][0]=x;
							k[a][1]='\0';
							strcpy(k[a],strcat(k[a],y));
							z[a]=0;
							a++;
						}
						b=d-1;
						printf("Size %d\n",b+1);
						c=0;
						d=a-b;
						abcc(0);
						printf("\n");
						break;
					}
					else if(x==32)
					{
						scanf("%d%c",&e,&x);
						a=0;
						while(scanf("%c",&x)==1)
						{
							if(x==10)
							{
								break;
							}
							gets(y);
							k[a][0]=x;
							k[a][1]='\0';
							strcpy(k[a],strcat(k[a],y));
							z[a]=0;
							a++;
						}
						for(b=d-1;b<e;b++)
						{
							printf("Size %d\n",b+1);
							c=0;
							d=a-b;
							abcc(0);
							printf("\n");
						}
						break;
					}
					else if(x>47&&x<58)
					{
						d*=10;
						d+=x-48;
					}
				}
				break;
			}
		}
	}
	return 0;
}