#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i[]={2,1,4,7,4,8,3,6,4,7};
	char j[300],k[300],w[600],x;
	double y,z;
	while(scanf("%c",&j[0])==1)
	{
		gets(w);
		f=strlen(w);
		printf("%c",j[0]);
		printf("%s\n",w);
		h=0;
		if(j[0]=='-')
		{
			h=1;
			j[0]=0;
		}
		else if(j[0]==32||j[0]==48)
		{
			j[0]=0;
		}
		else
		{
			j[0]-=48;
		}
		if(j[0]==0)
		{
			for(a=1,c=0;c<f;c++)
			{
				if(w[c]!=48&&w[c]!=32)
				{
					break;
				}
			}
			if(w[c]=='*'||w[c]=='+')
			{
				x=w[c];
				c++;
			}
			else
			{
				for(a,c;c<f;c++)
				{
					if(w[c]==32||w[c]=='*'||w[c]=='+')
					{
						x=w[c];
						c++;
						break;
					}
					j[a]=w[c]-48;
					a++;
				}
				if(x==32)
				{
					for(c;c<f;c++)
					{
						if(w[c]=='*'||w[c]=='+')
						{
							x=w[c];
							c++;
							break;
						}
					}
				}
				a--;
			}
		}
		else
		{
			for(a=1,c=0;c<f;c++)
			{
				if(w[c]==32||w[c]=='*'||w[c]=='+')
				{
					x=w[c];
					c++;
					break;
				}
				j[a]=w[c]-48;
				a++;
			}
			if(x==32)
			{
				for(c;c<f;c++)
				{
					if(w[c]=='*'||w[c]=='+')
					{
						x=w[c];
						c++;
						break;
					}
				}
			}
		}
		for(b=0,c;c<f;c++)
		{
			if(w[c]=='-')
			{
				h+=2;
			}
			else if(w[c]!=48&&w[c]!=32)
			{
				b++;
				k[0]=w[c]-48;
				c++;
				break;
			}
		}
		if(b==0)
		{
			b=1;
			k[0]=0;
		}
		else
		{
			for(b,c;c<f;c++,b++)
			{
				if(w[c]==32)
				{
					break;
				}
				k[b]=w[c]-48;
			}
		}
		c=0;
		if(a>10&&h%2==0)
		{
			printf("first number too big\n");
			c=1;
		}
		else if(a==10&&h%2==0)
		{
			for(d=0,y=0;d<10;d++)
			{
				y*=10;
				y+=j[d];
			}
			if(y>2147483647)
			{
				printf("first number too big\n");
				c=1;
			}
		}
		if(b>10&&h<2)
		{
			printf("second number too big\n");
			c+=2;
		}
		else if(b==10&&h<2)
		{
			for(d=0,y=0;d<10;d++)
			{
				y*=10;
				y+=k[d];
			}
			if(y>2147483647)
			{
				printf("second number too big\n");
				c+=2;
			}
		}
		if(c>0)
		{
			if(a==1)
			{
				if(j[0]==0&&x=='*')
				{
					continue;
				}
			}
			if(b==1)
			{
				if(k[0]==0&&x=='*')
				{
					continue;
				}
			}
			if(h==1||h==2)
			{
				continue;
			}
			printf("result too big\n");
		}
		else if(h!=1&&h!=2)
		{
			if(x=='*')
			{
				if(a+b>10)
				{
					if(a==1)
					{
						if(j[0]==1||j[0]==0)
						{
							continue;
						}
					}
					if(b==1)
					{
						
						if(k[0]==1||k[0]==0)
						{
							continue;
						}
					}
					printf("result too big\n");
				}
				else if(a+b>8)
				{
					for(c=0,y=0;c<a;c++)
					{
						y*=10;
						y+=j[c];
					}
					for(c=0,z=0;c<b;c++)
					{
						z*=10;
						z+=k[c];
					}
					y*=z;
					if(y>2147483647)
					{
						printf("result too big\n");
					}
				}
			}
			else
			{
				if(a>8||b>8)
				{
					for(c=0,y=0;c<a;c++)
					{
						y*=10;
						y+=j[c];
					}
					for(c=0,z=0;c<b;c++)
					{
						z*=10;
						z+=k[c];
					}
					y+=z;
					if(y>2147483647)
					{
						printf("result too big\n");
					}
				}
			}
		}
	}
	return 0;
}