#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,l[6401][2],y[6401][2],p,q,m,n;
	char k[77][78],w[2],x[78],z[77][78];
	w[0]=32;
	w[1]=0;
	for(a=0;a<77;a++)
	{
		k[0][a]=32;
	}
	k[0][a]=0;
	h=0;
	while(scanf("%d%d",&b,&a)==2)
	{
		if(a==0&&b==0)
		{
			break;
		}
		gets(x);
		a++;
		for(c=1;c<a;c++)
		{
			gets(x);
			strcpy(k[c],w);
			strcat(k[c],x);
			strcat(k[c],w);
		}
		strcpy(k[c],w);
		b++;
		for(c=1;c<b;c++)
		{
			k[a][c]=32;
		}
		k[a][b]=0;
		strcat(k[a],w);
		g=0;
		printf("Board #%d:\n",++h);
		while(scanf("%d%d%d%d",&d,&c,&f,&e)==4)
		{
			if(c==0&&d==0&&e==0&&f==0)
			{
				break;
			}
			for(a++,i=0;i<a;i++)
			{
				strcpy(z[i],k[i]);
			}
			a--;
			y[0][0]=c;
			y[0][1]=d;
			l[0][0]=0;
			l[0][1]=0;
			for(p=0,q=1,m=0;p<q;p++)
			{
				i=y[p][0];
				j=y[p][1];
				if(i<a)
				{
					if(z[i+1][j]=='X')
					{
						if(i+1==e&&j==f)
						{
							n=l[p][1];
							if(l[p][0]!=1)
							{
								n++;
							}
							if(n<m||!m)
							{
								m=n;
							}
						}
					}
					else
					{
						z[i+1][j]='X';
						y[q][0]=i+1;
						y[q][1]=j;
						l[q][0]=1;
						l[q][1]=l[p][1];
						if(l[p][0]!=1)
						{
							l[q][1]++;
						}
						q++;
					}
				}
				if(j<b)
				{
					if(z[i][j+1]=='X')
					{
						if(i==e&&j+1==f)
						{
							n=l[p][1];
							if(l[p][0]!=2)
							{
								n++;
							}
							if(n<m||!m)
							{
								m=n;
							}
						}
					}
					else
					{
						z[i][j+1]='X';
						y[q][0]=i;
						y[q][1]=j+1;
						l[q][0]=2;
						l[q][1]=l[p][1];
						if(l[p][0]!=2)
						{
							l[q][1]++;
						}
						q++;
					}
				}
				if(i>0)
				{
					if(z[i-1][j]=='X')
					{
						if(i-1==e&&j==f)
						{
							n=l[p][1];
							if(l[p][0]!=3)
							{
								n++;
							}
							if(n<m||!m)
							{
								m=n;
							}
						}
					}
					else
					{
						z[i-1][j]='X';
						y[q][0]=i-1;
						y[q][1]=j;
						l[q][0]=3;
						l[q][1]=l[p][1];
						if(l[p][0]!=3)
						{
							l[q][1]++;
						}
						q++;
					}
				}
				if(j>0)
				{
					if(z[i][j-1]=='X')
					{
						if(i==e&&j-1==f)
						{
							n=l[p][1];
							if(l[p][0]!=4)
							{
								n++;
							}
							if(n<m||!m)
							{
								m=n;
							}
						}
					}
					else
					{
						z[i][j-1]='X';
						y[q][0]=i;
						y[q][1]=j-1;
						l[q][0]=4;
						l[q][1]=l[p][1];
						if(l[p][0]!=4)
						{
							l[q][1]++;
						}
						q++;
					}
				}
			}
			printf("Pair %d: ",++g);
			if(m==0)
			{
				printf("impossible.\n");
			}
			else
			{
				printf("%d segments.\n",m);
			}
		}
		printf("\n");
	}
	return 0;
}