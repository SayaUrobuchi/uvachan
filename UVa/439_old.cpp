#include<stdio.h>
int main()
{
	char x[4],y[4],z;
	int a=0,b,c,d,e,f,g,h,i,j[64][2],k[9][9];
	for(a=1;a<9;a++)
	{
		for(b=1;b<9;b++)
		{
			k[a][b]=0;
		}
	}
	a=0;
	b=0;
	while(scanf("%c",&z)==1)
	{
		if(z!=32)
		{
			if(z==10)
			{
				if(x[0]==x[2]&&x[1]==x[3])
				{
					printf("To get from %c%c to %c%c takes 0 knight moves.\n",y[0],y[1],y[2],y[3]);
					a=0;
					continue;
				}
				for(b-=1;b>=0;b--)
				{
					c=j[b][0];
					d=j[b][1];
					k[c][d]=0;
				}
				j[0][0]=x[0];
				j[0][1]=x[1];
				k[x[0]][x[1]]=0;
				for(a=0,b=1,e=x[2],f=x[3];a<64;a++)
				{
					c=j[a][0];
					d=j[a][1];
					if(c>1&&d>2)
					{
						if(c-1==e&&d-2==f)
						{
							i=k[c][d]+1;
							break;
						}
						else
						{
							if(k[c-1][d-2]==0)
							{
								j[b][0]=c-1;
								j[b][1]=d-2;
								k[c-1][d-2]=k[c][d]+1;
								b++;
							}
						}
					}
					if(c>2&&d>1)
					{
						if(c-2==e&&d-1==f)
						{
							i=k[c][d]+1;
							break;
						}
						else
						{
							if(k[c-2][d-1]==0)
							{
								j[b][0]=c-2;
								j[b][1]=d-1;
								k[c-2][d-1]=k[c][d]+1;
								b++;
							}
						}
					}
					if(c<8&&d<7)
					{
						if(c+1==e&&d+2==f)
						{
							i=k[c][d]+1;
							break;
						}
						else
						{
							if(k[c+1][d+2]==0)
							{
								j[b][0]=c+1;
								j[b][1]=d+2;
								k[c+1][d+2]=k[c][d]+1;
								b++;
							}
						}
					}
					if(c<7&&d<8)
					{
						if(c+2==e&&d+1==f)
						{
							i=k[c][d]+1;
							break;
						}
						else
						{
							if(k[c+2][d+1]==0)
							{
								j[b][0]=c+2;
								j[b][1]=d+1;
								k[c+2][d+1]=k[c][d]+1;
								b++;
							}
						}
					}
					if(c>1&&d<7)
					{
						if(c-1==e&&d+2==f)
						{
							i=k[c][d]+1;
							break;
						}
						else
						{
							if(k[c-1][d+2]==0)
							{
								j[b][0]=c-1;
								j[b][1]=d+2;
								k[c-1][d+2]=k[c][d]+1;
								b++;
							}
						}
					}
					if(c>2&&d<8)
					{
						if(c-2==e&&d+1==f)
						{
							i=k[c][d]+1;
							break;
						}
						else
						{
							if(k[c-2][d+1]==0)
							{
								j[b][0]=c-2;
								j[b][1]=d+1;
								k[c-2][d+1]=k[c][d]+1;
								b++;
							}
						}
					}
					if(c<8&&d>2)
					{
						if(c+1==e&&d-2==f)
						{
							i=k[c][d]+1;
							break;
						}
						else
						{
							if(k[c+1][d-2]==0)
							{
								j[b][0]=c+1;
								j[b][1]=d-2;
								k[c+1][d-2]=k[c][d]+1;
								b++;
							}
						}
					}
					if(c<7&&d>1)
					{
						if(c+2==e&&d-1==f)
						{
							i=k[c][d]+1;
							break;
						}
						else
						{
							if(k[c+2][d-1]==0)
							{
								j[b][0]=c+2;
								j[b][1]=d-1;
								k[c+2][d-1]=k[c][d]+1;
								b++;
							}
						}
					}
				}
				/*for(a=0;a<b;a++)
				{
					printf("%d\n",j[a]);
				}
				for(a=1;a<9;a++)
				{
					for(c=1;c<9;c++)
					{
						printf("%d",k[a][c]);
					}
					printf("\n");
				}*/
				printf("To get from %c%c to %c%c takes %d knight moves.\n",y[0],y[1],y[2],y[3],i);
				a=0;
			}
			else
			{
				y[a]=z;
				if(z>60)
				{
					x[a]=y[a]-96;
				}
				else
				{
					x[a]=y[a]-48;
				}
				a++;
			}
		}
	}
	return 0;
}