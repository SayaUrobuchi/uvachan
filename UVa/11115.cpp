#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[27];
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a&&!b)
		{
			break;
		}
		k[0]=1;
		for(c=1;b>0;b--)
		{
			k[c]=0;
			for(d=0;d<c;d++)
			{
				k[d]*=a;
			}
			for(d=0;d<c;d++)
			{
				if(k[d]>9)
				{
					k[d+1]+=k[d]/10;
					k[d]%=10;
				}
			}
			if(k[d])
			{
				c++;
			}
		}
		for(c--;c>-1;c--)
		{
			printf("%d",k[c]);
		}
		printf("\n");
	}
	return 0;
}