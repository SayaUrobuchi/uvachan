#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i[101];
	bool j[101][101];
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a==0&&b==0)
		{
			break;
		}
		a++;
		for(d=1;d<a;d++)
		{
			for(c=1;c<a;c++)
			{
				j[d][c]=0;
			}
		}
		for(b;b>0;b--)
		{
			scanf("%d%d",&c,&d);
			j[c][d]=1;
		}
		for(b=1;b<a;b++)
		{
			i[b]=0;
			for(c=1;c<a;c++)
			{
				i[b]+=j[c][b];
			}
		}
		for(b=1,d=0;b<a;b++)
		{
			if(i[b]==0)
			{
				if(d==1)
				{
					printf(" ");
				}
				printf("%d",b);
				d=1;
				i[b]--;
				for(c=1;c<a;c++)
				{
					i[c]-=j[b][c];
				}
				b=0;
			}
		}
		printf("\n");
	}
	return 0;
}