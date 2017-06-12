#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,z[90];
	z['P']='S';
	z['S']='R';
	z['R']='P';
	char k[110][110],x[110][110],y, check;
	check = 0;
	scanf("%d",&g);
	for(g;g>0;g--)
	{
		if(check) printf("\n");
		check = 1;
		scanf("%d %d %d%c",&a,&b,&h,&y);
		for(c=0;c<a;c++)
		{
			gets(k[c]);
		}
		for(c=0;c<a;c++)
		{
			x[c][b]='\0';
		}
		for(h;h>0;h--)
		{
			for(c=0;c<a;c++)
			{
				for(d=0;d<b;d++)
				{
					if(c>0)
					{
						if(k[c-1][d]==z[k[c][d]])
						{
							x[c][d]=k[c-1][d];
							continue;
						}
					}
					if(c<a-1)
					{
						if(k[c+1][d]==z[k[c][d]])
						{
							x[c][d]=k[c+1][d];
							continue;
						}
					}
					if(d>0)
					{
						if(k[c][d-1]==z[k[c][d]])
						{
							x[c][d]=k[c][d-1];
							continue;
						}
					}
					if(d<b-1)
					{
						if(k[c][d+1]==z[k[c][d]])
						{
							x[c][d]=k[c][d+1];
							continue;
						}
					}
					x[c][d]=k[c][d];
				}
			}
			for(c=0;c<a;c++)
			{
				strcpy(k[c],x[c]);
			}
		}
		for(c=0;c<a;c++)
		{
			printf("%s\n",k[c]);
		}
	}
	return 0;
}
