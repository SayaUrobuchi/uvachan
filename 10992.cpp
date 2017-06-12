#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h;
	bool i,j,k[10];
	char x[51], check;
	check = 0;
	while(gets(x))
	{
		if(strcmp(x,"0")==0)
		{
			break;
		}
		if(check) printf("\n");
		check = 1;
		printf("%s\n",x);
		i=0;
		j=0;
		for(b=2;b<10;b++)
		{
			k[b]=0;
		}
		a=strlen(x);
		for(b=0;b<a;b++)
		{
			x[b]-=48;
		}
		if(a<5)
		{
			for(b=0,c=0;b<a;b++)
			{
				c*=10;
				c+=x[b];
			}
			if(c<2148)
			{
				printf("No ghost will come in this year\n");
				continue;
			}
		}
		for(b=0,c=a-1;b<=c;b++,c--)
		{
			d=x[b];
			x[b]=x[c];
			x[c]=d;
		}
		b=x[0]+x[1]*10;
		if(b%4==0)
		{
			k[4]=1;
		}
		if(k[4])
		{
			if(x[0]==0&&x[1]==0)
			{
				c=x[0]+x[1]*10+x[2]*100+x[3]*1000;
				if(c%16==0)
				{
					i=1;
				}
			}
			else
			{
				i=1;
			}
		}
		x[0]-=8;
		x[1]-=4;
		x[2]-=1;
		x[3]-=2;
		for(b=0;b<a;b++)
		{
			if(x[b]<0)
			{
				x[b]+=10;
				x[b+1]--;
			}
		}
		if(x[a-1]==0)
		{
			a--;
		}
		if(x[0]%2==0)
		{
			k[2]=1;
			printf("Ghost of Tanveer Ahsan!!!\n");
			j=1;
		}
		for(b=0,c=0;b<a;b++)
		{
			c+=x[b];
		}
		if(c%3==0)
		{
			k[3]=1;
		}
		if(c%9==0)
		{
			k[9]=1;
		}
		if(x[0]==0||x[0]==5)
		{
			k[5]=1;
			printf("Ghost of Shahriar Manzoor!!!\n");
			j=1;
		}
		for(b=a-1,c=0;b>-1;b--)
		{
			c*=10;
			c+=x[b];
			c%=7;
		}
		if(c==0)
		{
			k[7]=1;
			printf("Ghost of Adrian Kugel!!!\n");
			j=1;
		}
		for(b=0,c=0,d=1;b<a;b++)
		{
			c+=x[b]*d;
			d*=-1;
		}
		if(c%11==0)
		{
			printf("Ghost of Anton Maydell!!!\n");
			j=1;
		}
		if(k[3]&&k[5])
		{
			printf("Ghost of Derek Kisman!!!\n");
			j=1;
		}
		if(k[4]&&k[5])
		{
			printf("Ghost of Rezaul Alam Chowdhury!!!\n");
			j=1;
		}
		if(k[4]&&k[7])
		{
			printf("Ghost of Jimmy Mardell!!!\n");
			j=1;
		}
		if(k[4]&&k[9])
		{
			printf("Ghost of Monirul Hasan!!!\n");
			j=1;
		}
		if(i)
		{
			printf("Ghost of K. M. Iftekhar!!!\n");
		}
		if(j==0)
		{
			printf("No ghost will come in this year\n");
		}
	}
	return 0;
}
