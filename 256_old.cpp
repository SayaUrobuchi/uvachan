#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	int x[9][9],y[9];
	x[2][0]=0;
	x[2][1]=1;
	x[2][2]=81;
	y[2]=3;
	x[4][0]=0;
	x[4][1]=1;
	x[4][2]=2025;
	x[4][3]=3025;
	x[4][4]=9801;
	y[4]=5;
	x[6][0]=0;
	x[6][1]=1;
	x[6][2]=88209;
	x[6][3]=494209;
	x[6][4]=998001;
	y[6]=5;
	x[8][0]=0;
	x[8][1]=1;
	x[8][2]=4941729;
	x[8][3]=7441984;
	x[8][4]=24502500;
	x[8][5]=25502500;
	x[8][6]=52881984;
	x[8][7]=60481729;
	x[8][8]=99980001;
	y[8]=9;
	while(scanf("%d",&k)==1)
	{
		for(i=0;i<y[k];i++)
		{
			if(k==2)
			{
				printf("%02d\n",x[k][i]);
			}
			else if(k==4)
			{
				printf("%04d\n",x[k][i]);
			}
			else if(k==6)
			{
				printf("%06d\n",x[k][i]);
			}
			else
			{
				printf("%08d\n",x[k][i]);
			}
		}
		/*for(a=0,i=1,j=1;a<k;a+=2)
		{
			j*=10;
			i*=100;
		}
		for(a=0;a<i;a++)
		{
			b=a/j;
			b+=a%j;
			if(a==b*b)
			{
				if(k==2)
				{
					printf("%02d\n",a);
				}
				else if(k==4)
				{
					printf("%04d\n",a);
				}
				else if(k==6)
				{
					printf("%06d\n",a);
				}
				else
				{
					printf("%08d\n",a);
				}
			}
		}*/
	}
	return 0;
}