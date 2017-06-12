#include<stdio.h>
int a[5][5],b,c,d=0,e[9],f,g=0;
int abc(int b)
{
	if(c==8)
	{
		printf("%d%d\n",g,b+=1);
	}
	else
	{
		for(e[c]=0;e[c]<5;e[c]++)
		{
			if(e[c]!=b&&a[e[c]][b]==1)
			{
				g*=10;
				g+=b;
				g++;
				a[e[c]][b]=0;
				a[b][e[c]]=0;
				c++;
				abc(e[c-1]);
				c--;
				a[e[c]][b]=1;
				a[b][e[c]]=1;
				g/=10;
			}
		}
	}
	return 0;
}
int main()
{
	for(b=0;b<5;b++)
	{
		for(c=5;c>0;c--)
		{
			a[b][c-1]=1;
		}
	}
	a[0][3]=0;
	a[1][3]=0;
	a[3][0]=0;
	a[3][1]=0;
	b=0;
	abc(b);
	return 0;
}