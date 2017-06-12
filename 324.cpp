#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j[367][10],k[782];
	k[0]=1;
	for(a=1;a<782;a++)
	{
		k[a]=0;
	}
	for(a=1,b=1;a<367;a++)
	{
		for(c=0;c<b;c++)
		{
			k[c]*=a;
		}
		for(c=0;c<b;c++)
		{
			k[c+1]+=k[c]/10;
			k[c]%=10;
		}
		for(c;k[c]>9;c++)
		{
			k[c+1]+=k[c]/10;
			k[c]%=10;
		}
		if(k[c]==0)
		{
			c--;
		}
		b=c+1;
		for(d=0;d<10;d++)
		{
			j[a][d]=0;
		}
		for(c;c>=0;c--)
		{
			j[a][k[c]]++;
		}
	}
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		printf("%d! --\n",a);
		printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",j[a][0],j[a][1],j[a][2],j[a][3],j[a][4]);
		printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",j[a][5],j[a][6],j[a][7],j[a][8],j[a][9]);
	}
	return 0;
}