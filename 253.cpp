#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g;
	char h[7],i[7],j[7],k[13];
	while(scanf("%s",&k)==1)
	{
		i[0]=k[0];
		i[1]=k[5];
		i[2]=k[1];
		i[3]=k[2];
		i[4]=k[4];
		i[5]=k[3];
		i[6]='\0';
		j[0]=k[6];
		j[1]=k[11];
		j[2]=k[7];
		j[3]=k[8];
		j[4]=k[10];
		j[5]=k[9];
		j[6]='\0';
		if(strcmp(i,j)==0)
		{
			printf("TRUE\n");
			continue;
		}
		for(a=0,b=0,c=0,d=0;a<6;a++)
		{
			if(i[a]=='r')
			{
				b++;
			}
			else if(i[a]=='g')
			{
				c++;
			}
			else
			{
				d++;
			}
			if(j[a]=='r')
			{
				b--;
			}
			else if(j[a]=='g')
			{
				c--;
			}
			else
			{
				d--;
			}
		}
		if(b!=0||c!=0||d!=0)
		{
			printf("FALSE\n");
			continue;
		}
		strcpy(h,j);
		if(i[0]==j[0])
		{
			if(i[1]==j[1])
			{
				for(c=0;c<3;c++)
				{
					b=j[2];
					for(a=2;a<5;a++)
					{
						j[a]=j[a+1];
					}
					j[5]=b;
					if(strcmp(i,j)==0)
					{
						printf("TRUE\n");
						break;
					}
				}
				if(c<3)
				{
					continue;
				}
				strcpy(j,h);
			}
		}
		if(i[0]==j[1])
		{
			if(i[1]==j[0])
			{
				b=j[0];
				j[0]=j[1];
				j[1]=b;
				b=j[2];
				j[2]=j[4];
				j[4]=b;
				if(strcmp(i,j)==0)
				{
					printf("TRUE\n");
					continue;
				}
				for(c=0;c<3;c++)
				{
					b=j[2];
					for(a=2;a<5;a++)
					{
						j[a]=j[a+1];
					}
					j[5]=b;
					if(strcmp(i,j)==0)
					{
						printf("TRUE\n");
						break;
					}
				}
				if(c<3)
				{
					continue;
				}
				strcpy(j,h);
			}
		}
		if(i[0]==j[2])
		{
			if(i[1]==j[4])
			{
				b=j[0];
				j[0]=j[2];
				j[2]=j[1];
				j[1]=j[4];
				j[4]=b;
				if(strcmp(i,j)==0)
				{
					printf("TRUE\n");
					continue;
				}
				for(c=0;c<3;c++)
				{
					b=j[2];
					for(a=2;a<5;a++)
					{
						j[a]=j[a+1];
					}
					j[5]=b;
					if(strcmp(i,j)==0)
					{
						printf("TRUE\n");
						break;
					}
				}
				if(c<3)
				{
					continue;
				}
				strcpy(j,h);
			}
		}
		if(i[0]==j[3])
		{
			if(i[1]==j[5])
			{
				b=j[0];
				j[0]=j[3];
				j[3]=j[1];
				j[1]=j[5];
				j[5]=b;
				if(strcmp(i,j)==0)
				{
					printf("TRUE\n");
					continue;
				}
				for(c=0;c<3;c++)
				{
					b=j[2];
					for(a=2;a<5;a++)
					{
						j[a]=j[a+1];
					}
					j[5]=b;
					if(strcmp(i,j)==0)
					{
						printf("TRUE\n");
						break;
					}
				}
				if(c<3)
				{
					continue;
				}
				strcpy(j,h);
			}
		}
		if(i[0]==j[4])
		{
			if(i[1]==j[2])
			{
				b=j[0];
				j[0]=j[4];
				j[4]=j[1];
				j[1]=j[2];
				j[2]=b;
				if(strcmp(i,j)==0)
				{
					printf("TRUE\n");
					continue;
				}
				for(c=0;c<3;c++)
				{
					b=j[2];
					for(a=2;a<5;a++)
					{
						j[a]=j[a+1];
					}
					j[5]=b;
					if(strcmp(i,j)==0)
					{
						printf("TRUE\n");
						break;
					}
				}
				if(c<3)
				{
					continue;
				}
				strcpy(j,h);
			}
		}
		if(i[0]==j[5])
		{
			if(i[1]==j[3])
			{
				b=j[0];
				j[0]=j[5];
				j[5]=j[1];
				j[1]=j[3];
				j[3]=b;
				if(strcmp(i,j)==0)
				{
					printf("TRUE\n");
					continue;
				}
				for(c=0;c<3;c++)
				{
					b=j[2];
					for(a=2;a<5;a++)
					{
						j[a]=j[a+1];
					}
					j[5]=b;
					if(strcmp(i,j)==0)
					{
						printf("TRUE\n");
						break;
					}
				}
				if(c<3)
				{
					continue;
				}
			}
		}
		printf("FALSE\n");
	}
	return 0;
}