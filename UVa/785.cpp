#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,y[2500][2];
	char k[40][81],x,z;
	a=0;
	while(gets(k[a]))
	{
		if(k[a][0]=='_')
		{
			for(b=0;b<a;b++)
			{
				for(c=0;k[b][c]!='\0';c++)
				{
					if(k[b][c]!=32)
					{
						x=k[b][c];
						break;
					}
				}
				if(k[b][c]!='\0')
				{
					break;
				}
			}
			for(b;b<a;b++)
			{
				for(c=0;k[b][c]!='\0';c++)
				{
					if(k[b][c]!=x&&k[b][c]!=32)
					{
						z=k[b][c];
						y[0][0]=b;
						y[0][1]=c;
						d=1;
						for(e=0;e<d;e++)
						{
							i=y[e][0];
							j=y[e][1];
							if(k[i-1][j]==32)
							{
								k[i-1][j]=z;
								y[d][0]=i-1;
								y[d][1]=j;
								d++;
							}
							if(k[i+1][j]==32)
							{
								k[i+1][j]=z;
								y[d][0]=i+1;
								y[d][1]=j;
								d++;
							}
							if(k[i][j-1]==32)
							{
								k[i][j-1]=z;
								y[d][0]=i;
								y[d][1]=j-1;
								d++;
							}
							if(k[i][j+1]==32)
							{
								k[i][j+1]=z;
								y[d][0]=i;
								y[d][1]=j+1;
								d++;
							}
						}
					}
				}
			}
			a++;
			for(b=0;b<a;b++)
			{
				printf("%s\n",k[b]);
			}
			a=0;
			break;
		}
		a++;
	}
	while(scanf("%c",&x)==1)
	{
		printf("%c",x);
		while(gets(k[a]))
	{
		if(k[a][0]=='_')
		{
			for(b=0;b<a;b++)
			{
				for(c=0;k[b][c]!='\0';c++)
				{
					if(k[b][c]!=32)
					{
						x=k[b][c];
						break;
					}
				}
				if(k[b][c]!='\0')
				{
					break;
				}
			}
			for(b;b<a;b++)
			{
				for(c=0;k[b][c]!='\0';c++)
				{
					if(k[b][c]!=x&&k[b][c]!=32)
					{
						z=k[b][c];
						y[0][0]=b;
						y[0][1]=c;
						d=1;
						for(e=0;e<d;e++)
						{
							i=y[e][0];
							j=y[e][1];
							if(k[i-1][j]==32)
							{
								k[i-1][j]=z;
								y[d][0]=i-1;
								y[d][1]=j;
								d++;
							}
							if(k[i+1][j]==32)
							{
								k[i+1][j]=z;
								y[d][0]=i+1;
								y[d][1]=j;
								d++;
							}
							if(k[i][j-1]==32)
							{
								k[i][j-1]=z;
								y[d][0]=i;
								y[d][1]=j-1;
								d++;
							}
							if(k[i][j+1]==32)
							{
								k[i][j+1]=z;
								y[d][0]=i;
								y[d][1]=j+1;
								d++;
							}
						}
					}
				}
			}
			a++;
			for(b=0;b<a;b++)
			{
				printf("%s\n",k[b]);
			}
			a=-1;
		}
		a++;
	}
	}
	return 0;
}