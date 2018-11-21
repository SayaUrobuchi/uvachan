#include<stdio.h>
#include<string.h>
int abcc(int y)
{
	if(y==0)
	{
		return 'N';
	}
	else if(y==1)
	{
		return 'E';
	}
	else if(y==2)
	{
		return 'S';
	}
	else
	{
		return 'W';
	}
}
int main()
{
	int a,b,c,e,f,g,h,i,j;
	unsigned int d;
	char k[65][65],x[200], check;
	check = 0;
	scanf("%d",&g);
	for(g;g>0;g--)
	{
		scanf("%d %d\n",&a,&b);
		for(c=0;c<a;c++)
		{
			gets(k[c]);
		}
		scanf("%d %d\n",&i,&j);
		i--;
		j--;
		d=0;
		f=0;
		for(;;)
		{
			gets(x);
			h=strlen(x);
			if(h==0&&g!=1)
			{
				break;
			}
			else if(f==1&&g==1)
			{
				break;
			}
			if(f==0)
			{
				for(c=0;c<h;c++)
				{
					if(f==0)
					{
						if(x[c]=='R')
						{
							d++;
							d%=4;
						}
						else if(x[c]=='L')
						{
							d--;
							d%=4;
						}
						else if(x[c]=='F')
						{
							if(d==0)
							{
								if(i>0)
								{
									if(k[i-1][j]==32)
									{
										i--;
										continue;
									}
								}
							}
							if(d==2)
							{
								if(i<a-1)
								{
									if(k[i+1][j]==32)
									{
										i++;
										continue;
									}
								}
							}
							if(d==1)
							{
								if(j<b-1)
								{
									if(k[i][j+1]==32)
									{
										j++;
										continue;
									}
								}
							}
							if(d==3)
							{
								if(j>0)
								{
									if(k[i][j-1]==32)
									{
										j--;
										continue;
									}
								}
							}
						}
						else if(x[c]=='Q')
						{
							if(check) printf("\n");
							check = 1;
							x[0]=abcc(d);
							printf("%d %d %c\n",i+1,j+1,x[0]);
							f=1;
							break;
						}
					}
				}
			}
		}
	}
	return 0;
}
