#include<stdio.h>
#include<string.h>
char g[2000],y;
char *pch;
int a,b,c,d,e,h,i,j[101][101],k[101][101],x;
int f;
int main()
{
	for(c=0;c<101;c++)
	{
		j[c][0]=0;
		j[0][c]=0;
	}
	h=0;
	fgets(g, 2000, stdin);
	g[strlen(g)-1] = 0;
	sscanf(g,"%d",&x);
	a=0;
	b=0;
	for(x;x>0;x--)
	{
	fgets(g, 2000, stdin);
	g[strlen(g)-1] = 0;
	fgets(g, 2000, stdin);
	g[strlen(g)-1] = 0;
		for(c=1;c<=a;c++)
				{
					for(d=1;d<=b;d++)
					{
						k[c][d]=0;
					}
				}
		sscanf(g,"%d %d",&a,&b);
			for(c=1;c<=a;c++)
			{
	fgets(g, 2000, stdin);
	g[strlen(g)-1] = 0;
				pch=strtok(g," ");
				pch=strtok(NULL," ");
				while(pch!=NULL)
				{
					sscanf(pch,"%d",&e);
					k[c][e]=1;
					pch=strtok(NULL," ");
				}
			}
			j[1][1]=1;
			for(c=1;c<=a;c++)
			{
				for(d=1;d<=b;d++)
				{
					if(c==1&&d==1)
					{
						continue;
					}
					if(k[c][d]==1)
					{
						j[c][d]=0;
						//printf(" 0 ");
						continue;
					}
					j[c][d]=j[c-1][d]+j[c][d-1];
					//printf("%2d ",j[c][d]);
				}
				//printf("\n");
			}
			if(h==1)
			{
				printf("\n");
			}
			h=1;
			printf("%d\n",j[a][b]);
	}
	return 0;
}
