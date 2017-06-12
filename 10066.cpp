#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j[105],k[105][105];
	f=0;
	while(scanf("%d %d",&a,&b)==2)
	{
		f++;
		if(a==0&&b==0)
		{
			break;
		}
		for(c=1;c<=a;c++)
		{
			scanf("%d",&j[c]);
			k[c-1][0]=0;
		}
		for(c=1;c<=b;c++)
		{
			scanf("%d",&i);
			k[0][c]=0;
			for(d=1;d<=a;d++)
			{
				if(i==j[d])
				{
					k[c][d]=k[c-1][d-1]+1;
				}
				else
				{
					k[c][d]=k[c-1][d];
					if(k[c][d-1]>k[c][d])
					{
						k[c][d]=k[c][d-1];
					}
				}
			}
		}
		/*if(g==1)
		{
			printf("\n");
		}
		g=1;*/
		printf("Twin Towers #%d\n",f);
		printf("Number of Tiles : %d\n\n",k[b][a]);
	}
	return 0;
}