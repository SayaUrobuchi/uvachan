#include<stdio.h>
#include<string.h>
int a,b,c,d,e,f,g,h,i,j;
char k[28][28],x[28], check;
int abcc()
{
	int y,z;
	strcpy(k[d],k[d+1]);
	if(c==-1)
	{
		printf("%s\n",k[d]);
		return 0;
	}
	c--;
	d--;
	abcc();
	c++;
	d++;
	for(y=c;y<b;y++)
	{
		x[27]=k[d][y];
		k[d][y]=k[d][y+1];
		k[d][y+1]=x[27];
		c--;
		d--;
		abcc();
		c++;
		d++;
	}
	return 0;
}
int main()
{
	check = 0;
	while(scanf("%s",&x)==1)
	{
		if(check) printf("\n");
		check = 1;
		a=strlen(x);
		b=a-1;
		strcpy(k[a],x);
		for(i=0,j=b;i<j;i++,j--)
		{
			x[27]=k[a][i];
			k[a][i]=k[a][j];
			k[a][j]=x[27];
		}
		c=b-1;
		d=b;
		abcc();
	}
	return 0;
}
