#include<stdio.h>
int a,b,c,d,e,f,g,h,k[64][1000],l[64];
int main()
{
	unsigned long long i,j;
	k[0][0]=1;
	l[0]=1;
	for(a=1;a<64;a++)
	{
		l[a]=l[a-1];
		for(b=0;b<l[a];b++)
		{
			k[a][b]=k[a-1][b]*3;
		}
		for(b=1;b<l[a];b++)
		{
			k[a][b]+=k[a][b-1]/10;
			k[a][b-1]%=10;
		}
		l[a]--;
		while(k[a][l[a]]>0)
		{
			k[a][l[a]+1]=k[a][l[a]]/10;
			k[a][l[a]]%=10;
			l[a]++;
		}
	}
	while(scanf("%llu",&i)==1)
	{
		if(!i)
		{
			break;
		}
		i--;
		printf("{");
		for(a=0,b=0;i>0;b++,i/=2)
		{
			if(i%2)
			{
				if(a)
				{
					printf(",");
				}
				a=1;
				printf(" ");
				for(c=l[b]-1;c>-1;c--)
				{
					printf("%d",k[b][c]);
				}
			}
		}
		printf(" }\n");
	}
	return 0;
}