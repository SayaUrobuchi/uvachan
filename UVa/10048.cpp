#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[100][100],l[100][100];
	char check;
	check = 0;
	h=0;
	while(scanf("%d%d%d",&a,&f,&g)==3)
	{
		if(!a&&!f&&!g)
		{
			break;
		}
		if(check) printf("\n");
		check = 1;
		for(b=0;b<a;b++)
		{
			for(c=0;c<a;c++)
			{
				k[b][c]=0;
			}
		}
		for(f;f>0;f--)
		{
			scanf("%d%d%d",&b,&c,&d);
			k[--b][--c]=d;
			k[c][b]=d;
		}
		for(b=0;b<a;b++)
		{
			for(c=0;c<a;c++)
			{
				l[b][c]=k[b][c];
			}
		}
		for(b=0;b<a;b++)
		{
			for(i=0;i<a;i++)
			{
				for(j=0;j<a;j++)
				{
					if(l[i][b]&&l[b][j])
					{
						c=l[i][b];
						if(c<l[b][j])
						{
							c=l[b][j];
						}
						if((c<l[i][j]&&c)||!l[i][j])
						{
							l[i][j]=c;
						}
					}
				}
			}
		}
		printf("Case #%d\n",++h);
		for(g;g>0;g--)
		{
			scanf("%d%d",&b,&c);
			if(l[--b][--c])
			{
				printf("%d\n",l[b][c]);
			}
			else
			{
				printf("no path\n");
			}
		}
	}
	return 0;
}
