#include<stdio.h>
#include<string.h>
int a,b,c,d,e,f,g,h,i,j[7];
char k[8][9],x,y[7];
int abcc()
{
	if(i==7)
	{
		if(j[0]==1)
		{
			printf("forth");
		}
		else if(j[0]==2)
		{
			printf("left");
		}
		else
		{
			printf("right");
		}
		for(e=1;e<7;e++)
		{
			if(j[e]==1)
			{
				printf(" forth");
			}
			else if(j[e]==2)
			{
				printf(" left");
			}
			else
			{
				printf(" right");
			}
		}
		printf("\n");
		return 1;
	}
	if(c>0)
	{
		if(k[c-1][d]==y[i])
		{
			j[i]=1;
			i++;
			c--;
			g=abcc();
			if(g==1)
			{
				return 1;
			}
			c++;
			i--;
		}
	}
	if(d>0)
	{
		if(k[c][d-1]==y[i])
		{
			j[i]=2;
			i++;
			d--;
			g=abcc();
			if(g==1)
			{
				return 1;
			}
			d++;
			i--;
		}
	}
	if(d<b-1)
	{
		if(k[c][d+1]==y[i])
		{
			j[i]=3;
			i++;
			d++;
			g=abcc();
			if(g==1)
			{
				return 1;
			}
			d--;
			i--;
		}
	}
	return 0;
}
int main()
{
	strcpy(y,"IEHOVA");
	y[6]='#';
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d%d%c",&a,&b,&x);
		for(c=0;c<a;c++)
		{
			gets(k[c]);
		}
		c=a-1;
		for(d=0;d<b;d++)
		{
			if(k[c][d]=='@')
			{
				break;
			}
		}
		i=0;
		abcc();
	}
	return 0;
}