#include<stdio.h>
#include<string.h>
char k[83682][6];
int main()
{
	int a,b,c,d,e,f,g,h,i,j[6];
	char x[6];
	for(a=0,i=1;a<5;a++)
	{
		for(b=97;b<123;b++)
		{
			if(a>0)
			{
				for(c=b+1;c<123;c++)
				{
					if(a>1)
					{
						for(d=c+1;d<123;d++)
						{
							if(a>2)
							{
								for(e=d+1;e<123;e++)
								{
									if(a>3)
									{
										for(f=e+1;f<123;f++)
										{
											k[i][0]=b;
											k[i][1]=c;
											k[i][2]=d;
											k[i][3]=e;
											k[i][4]=f;
											k[i++][5]='\0';
										}
									}
									else
									{
										k[i][0]=b;
										k[i][1]=c;
										k[i][2]=d;
										k[i][3]=e;
										k[i++][4]='\0';
									}
								}
							}
							else
							{
								k[i][0]=b;
								k[i][1]=c;
								k[i][2]=d;
								k[i++][3]='\0';
							}
						}
					}
					else
					{
						k[i][0]=b;
						k[i][1]=c;
						k[i++][2]='\0';
					}
				}
			}
			else
			{
				k[i][0]=b;
				k[i++][1]='\0';
			}
		}
	}
	j[0]=0;
	j[1]=26;
	j[2]=351;
	j[3]=2951;
	j[4]=17901;
	j[5]=83681;
	while(scanf("%s", x) == 1)
	{
		a=strlen(x);
		b=j[a-1]+1;
		c=j[a];
		while(1)
		{
			d=b+c;
			d/=2;
			e=strcmp(x,k[d]);
			if(e==0)
			{
				printf("%d\n",d);
				break;
			}
			else if(e<0)
			{
				c=d-1;
				if(b>c)
				{
					printf("0\n");
					break;
				}
			}
			else
			{
				b=d+1;
				if(b>c)
				{
					printf("0\n");
					break;
				}
			}
		}
	}
	return 0;
}