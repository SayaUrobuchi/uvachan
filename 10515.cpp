#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g;
	char i[105],j[105];
	while(scanf("%s%s",&i,&j)==2)
	{
		if(strcmp(i,"0")==0&&strcmp(j,"0")==0)
		{
			break;
		}
		if(strcmp(j,"0")==0)
		{
			printf("1\n");
			continue;
		}
		a=strlen(i);
		b=strlen(j);
		a--;
		b--;
		c=i[a]-48;
		if(c==0||c==1||c==5||c==6)
		{
			printf("%d\n",c);
			continue;
		}
		if(c==4)
		{
			d=j[b];
			if(d%2==1)
			{
				printf("4\n");
				continue;
			}
			printf("6\n");
			continue;
		}
		if(c==9)
		{
			d=j[b];
			if(d%2==1)
			{
				printf("9\n");
				continue;
			}
			printf("1\n");
			continue;
		}
		if(c==2)
		{
			d=j[b]-48;
			if(b>0)
			{
				d+=(j[b-1]-48)*10;
			}
			d%=4;
			if(d==1)
			{
				printf("2\n");
				continue;
			}
			if(d==2)
			{
				printf("4\n");
				continue;
			}
			if(d==3)
			{
				printf("8\n");
				continue;
			}
			if(d==0)
			{
				printf("6\n");
				continue;
			}
		}
		if(c==3)
		{
			d=j[b]-48;
			if(b>0)
			{
				d+=(j[b-1]-48)*10;
			}
			d%=4;
			if(d==1)
			{
				printf("3\n");
				continue;
			}
			if(d==2)
			{
				printf("9\n");
				continue;
			}
			if(d==3)
			{
				printf("7\n");
				continue;
			}
			if(d==0)
			{
				printf("1\n");
				continue;
			}
		}
		if(c==7)
		{
			d=j[b]-48;
			if(b>0)
			{
				d+=(j[b-1]-48)*10;
			}
			d%=4;
			if(d==1)
			{
				printf("7\n");
				continue;
			}
			if(d==2)
			{
				printf("9\n");
				continue;
			}
			if(d==3)
			{
				printf("3\n");
				continue;
			}
			if(d==0)
			{
				printf("1\n");
				continue;
			}
		}
		if(c==8)
		{
			d=j[b]-48;
			if(b>0)
			{
				d+=(j[b-1]-48)*10;
			}
			d%=4;
			if(d==1)
			{
				printf("8\n");
				continue;
			}
			if(d==2)
			{
				printf("4\n");
				continue;
			}
			if(d==3)
			{
				printf("2\n");
				continue;
			}
			if(d==0)
			{
				printf("6\n");
				continue;
			}
		}
	}
	return 0;
}