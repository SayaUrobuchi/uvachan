#include<stdio.h>
#include<string.h>
int a,b,c,d,e,f,g,h,i,j[9],k[92][9];
bool x[9];
char w[18],z[25], check;
int abcc()
{
	int y;
	if(e==9)
	{
		for(y=1;y<9;y++)
		{
			k[f][y]=j[y];
		}
		f++;
		return 0;
	}
	for(y=1;y<9;y++)
	{
		if(x[y])
		{
			for(b=1,c=e-1;b<e;b++,c--)
			{
				d=y-j[b];
				if(d<0)
				{
					d*=-1;
				}
				if(c==d)
				{
					break;
				}
			}
			if(b==e)
			{
				j[e]=y;
				x[y]=0;
				e++;
				abcc();
				e--;
				x[y]=1;
			}
		}
	}
}
int main()
{
	for(a=1,f=0;a<5;a++)
	{
		for(b=1;b<9;b++)
		{
			x[b]=1;
		}
		j[1]=a;
		x[a]=0;
		e=2;
		abcc();
	}
	for(a=f-1;a>-1;a--,f++)
	{
		for(b=1;b<9;b++)
		{
			k[f][b]=9-k[a][b];
		}
	}
	scanf("%d",&h);
	strcpy(w,"SOLN       COLUMN");
	strcpy(z," #      1 2 3 4 5 6 7 8");
	for(h;h>0;h--)
	{
		scanf("%d%d",&a,&b);
		if(check) printf("\n");
		check = 1;
		printf("%s\n%s\n\n",w,z);
		for(c=0,g=0;c<f;c++)
		{
			if(k[c][b]==a)
			{
				printf("%2d     ",++g);
				for(d=1;d<9;d++)
				{
					printf(" %d",k[c][d]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
