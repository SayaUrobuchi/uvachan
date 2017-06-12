#include<stdio.h>
char k[9][9],l[81][2],m,n, check;
int abcc(int p,int q)
{
	int a,b,i,j,w,x,y,z[10];
	if(p==m)
	{
		return 1;
	}
	b=q*q;
	i=l[p][0];
	j=l[p][1];
	for(b++,w=1;w<b;w++)
	{
		z[w]=1;
	}
	b--;
	for(w=0;w<b;w++)
	{
		if(k[w][j])
		{
			z[k[w][j]]=0;
		}
		if(k[i][w])
		{
			z[k[i][w]]=0;
		}
	}
	for(a=i-i%q,w=a+q,y=j-j%q+q;a<w;a++)
	{
		for(x=j-j%q;x<y;x++)
		{
			if(k[a][x])
			{
				z[k[a][x]]=0;
			}
		}
	}
	for(b++,w=1;w<b;w++)
	{
		if(z[w])
		{
			k[i][j]=w;
			if(abcc(p+1,q))
			{
				return 1;
			}
			k[i][j]=0;
		}
	}
	return 0;
}
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	check = 0;
	while(scanf("%d",&a)==1)
	{
		if(check) printf("\n");
		check = 1;
		for(b=0,d=a*a,m=0;b<d;b++)
		{
			for(c=0;c<d;c++)
			{
				scanf("%d",&k[b][c]);
			}
		}
		for(b=0;b<d;b++)
		{
			for(c=0;c<d;c++)
			{
				if(!k[c][b])
				{
					l[m][0]=c;
					l[m++][1]=b;
				}
			}
		}
		if(abcc(0,a))
		{
			for(b=0;b<d;b++)
			{
				printf("%d",k[b][0]);
				for(c=1;c<d;c++)
				{
					printf(" %d",k[b][c]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("NO SOLUTION\n");
		}
	}
	return 0;
}
