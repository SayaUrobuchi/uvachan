#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[10000];
char l[10][10];
bool m[10000];
int main()
{
	l[1][0]=0;
	l[1][1]=1;
	l[1][2]=2;
	l[1][3]=3;
	l[1][4]=4;
	l[1][5]=5;
	l[1][6]=6;
	l[1][7]=7;
	l[1][8]=8;
	l[1][9]=9;
	l[3][0]=0;
	l[3][1]=7;
	l[3][2]=4;
	l[3][3]=1;
	l[3][4]=8;
	l[3][5]=5;
	l[3][6]=2;
	l[3][7]=9;
	l[3][8]=6;
	l[3][9]=3;
	l[7][0]=0;
	l[7][1]=3;
	l[7][2]=6;
	l[7][3]=9;
	l[7][4]=2;
	l[7][5]=5;
	l[7][6]=8;
	l[7][7]=1;
	l[7][8]=4;
	l[7][9]=7;
	l[9][0]=0;
	l[9][1]=9;
	l[9][2]=8;
	l[9][3]=7;
	l[9][4]=6;
	l[9][5]=5;
	l[9][6]=4;
	l[9][7]=3;
	l[9][8]=2;
	l[9][9]=1;
	while(scanf("%d",&a)==1)
	{
		for(b=0;b<10000;b++)
		{
			k[b]=0;
			m[b]=0;
		}
		b=0;
		e=a%10;
		while(1)
		{
			if(k[b]==1)
			{
				b++;
				if(!m[b])
				{
					break;
				}
				continue;
			}
			c=11-k[b];
			c%=10;
			k[b]+=a*l[e][c];
			m[b]=1;
			c=b;
			while(k[c]>9)
			{
				k[c+1]+=k[c]/10;
				k[c]%=10;
				m[c++]=1;
			}
			if(k[c])
			{
				m[c]=1;
			}
			b++;
			if(!k[b]&&!m[b])
			{
				break;
			}
		}
		printf("%d\n",b);
	}
	return 0;
}