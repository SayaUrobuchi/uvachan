#include<stdio.h>
#include<string.h>
int main()
{
	char i[21][21],j[21][72],w,x[72];
	int a,b,c,d,e,f,g,h,k[21],y[21],z;
	h=0;
	z=0;
	while(scanf("%d %d\n",&a,&b)==2)
	{
		for(c=0;c<21;c++)
		{
			k[c]=0;
		}
		h++;
		for(c=0;c<a;c++)
		{
			gets(i[c]);
			y[c]=strlen(i[c]);
		}
		for(c=0;c<b;c++)
		{
			gets(j[c]);
			d=strlen(j[c]);
			for(e=0,f=0;e<d;e++)
			{
				if(j[c][e]>='A'&&j[c][e]<='Z')
				{
					x[f]=j[c][e]+32;
					f++;
				}
				else if(j[c][e]>='a'&&j[c][e]<='z')
				{
					x[f]=j[c][e];
					f++;
				}
				else
				{
					if(f>0)
					{
						x[f]='\0';
						for(g=0;g<a;g++)
						{
							if(y[g]==f)
							{
								if(strcmp(i[g],x)==0)
								{
									k[c]++;
									break;
								}
							}
						}
						f=0;
					}
				}
			}
			if(k[c]>z)
			{
				z=k[c];
			}
		}
		printf("Excuse Set #%d\n",h);
		for(c=0;c<b;c++)
		{
			if(k[c]==z)
			{
				printf("%s\n",j[c]);
			}
		}
		printf("\n");
		z=0;
	}
	return 0;
}