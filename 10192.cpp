#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,g,k[105][105];
	e=0;
	char i[105],j[105];
	while(gets(i))
	{
		e++;
		if(i[0]=='#')
		{
			break;
		}
		a=strlen(i);
		gets(j);
		b=strlen(j);
		for(c=0;c<=a;c++)
		{
			k[c][0]=0;
		}
		for(c=1;c<=b;c++)
		{
			k[0][c]=0;
		}
		for(c=1;c<=a;c++)
		{
			for(d=1;d<=b;d++)
			{
				if(i[c-1]==j[d-1])
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
		printf("Case #%d: you can visit at most %d cities.\n",e,k[a][b]);
	}
	return 0;
}