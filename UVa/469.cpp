#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,k,z[10100][2],p,q;
	char i[100][101],j[100][101],x,y;
	scanf("%d%c%c",&h,&x,&y);
	for(h;h>0;h--)
	{
		gets(i[0]);
		b=strlen(i[0]);
		a=1;
		while(gets(i[a]))
		{
			c=strlen(i[a]);
			if(c!=b)
			{
				for(d=0,e=0;d<c;d++)
				{
					if(i[a][d]>47&&i[a][d]<58)
					{
						e*=10;
						e+=i[a][d]-48;
					}
					else if(i[a][d]==32)
					{
						break;
					}
				}
				for(f=0;d<c;d++)
				{
					if(i[a][d]>47&&i[a][d]<58)
					{
						f*=10;
						f+=i[a][d]-48;
					}
				}
				break;
			}
			a++;
		}
		for(c=0;c<a;c++)
		{
			strcpy(j[c],i[c]);
		}
		z[0][0]=--e;
		z[0][1]=--f;
		j[e][f]='L';
		d=1;
		for(e=0;e<d;e++)
		{
			p=z[e][0];
			q=z[e][1];
			if(p>0)
			{
				if(q>0)
				{
					if(j[p-1][q-1]=='W')
					{
						j[p-1][q-1]='L';
						z[d][0]=p-1;
						z[d][1]=q-1;
						d++;
					}
				}
				if(j[p-1][q]=='W')
				{
					j[p-1][q]='L';
					z[d][0]=p-1;
					z[d][1]=q;
					d++;
				}
				if(q<b-1)
				{
					if(j[p-1][q+1]=='W')
					{
						j[p-1][q+1]='L';
						z[d][0]=p-1;
						z[d][1]=q+1;
						d++;
					}
				}
			}
			if(q>0)
			{
				if(j[p][q-1]=='W')
				{
					j[p][q-1]='L';
					z[d][0]=p;
					z[d][1]=q-1;
					d++;
				}
			}
			if(q<b-1)
			{
				if(j[p][q+1]=='W')
				{
					j[p][q+1]='L';
					z[d][0]=p;
					z[d][1]=q+1;
					d++;
				}
			}
			if(p<a-1)
			{
				if(q>0)
				{
					if(j[p+1][q-1]=='W')
					{
						j[p+1][q-1]='L';
						z[d][0]=p+1;
						z[d][1]=q-1;
						d++;
					}
				}
				if(j[p+1][q]=='W')
				{
					j[p+1][q]='L';
					z[d][0]=p+1;
					z[d][1]=q;
					d++;
				}
				if(q<b-1)
				{
					if(j[p+1][q+1]=='W')
					{
						j[p+1][q+1]='L';
						z[d][0]=p+1;
						z[d][1]=q+1;
						d++;
					}
				}
			}
		}
		printf("%d\n",d);
		e=0;
		while(scanf("%c",&x)==1)
		{
			if(x==10)
			{
				printf("\n");
				break;
			}
			if(x==32)
			{
				scanf("%d%c",&f,&x);
				for(c=0;c<a;c++)
				{
					strcpy(j[c],i[c]);
				}
				z[0][0]=--e;
				z[0][1]=--f;
				j[e][f]='L';
				d=1;
				for(e=0;e<d;e++)
				{
					p=z[e][0];
					q=z[e][1];
					if(p>0)
					{
						if(q>0)
						{
							if(j[p-1][q-1]=='W')
							{
								j[p-1][q-1]='L';
								z[d][0]=p-1;
								z[d][1]=q-1;
								d++;
							}
						}
						if(j[p-1][q]=='W')
						{
							j[p-1][q]='L';
							z[d][0]=p-1;
							z[d][1]=q;
							d++;
						}
						if(q<b-1)
						{
							if(j[p-1][q+1]=='W')
							{
								j[p-1][q+1]='L';
								z[d][0]=p-1;
								z[d][1]=q+1;
								d++;
							}
						}
					}
					if(q>0)
					{
						if(j[p][q-1]=='W')
						{
							j[p][q-1]='L';
							z[d][0]=p;
							z[d][1]=q-1;
							d++;
						}
					}
					if(q<b-1)
					{
						if(j[p][q+1]=='W')
						{
							j[p][q+1]='L';
							z[d][0]=p;
							z[d][1]=q+1;
							d++;
						}
					}
					if(p<a-1)
					{
						if(q>0)
						{
							if(j[p+1][q-1]=='W')
							{
								j[p+1][q-1]='L';
								z[d][0]=p+1;
								z[d][1]=q-1;
								d++;
							}
						}
						if(j[p+1][q]=='W')
						{
							j[p+1][q]='L';
							z[d][0]=p+1;
							z[d][1]=q;
							d++;
						}
						if(q<b-1)
						{
							if(j[p+1][q+1]=='W')
							{
								j[p+1][q+1]='L';
								z[d][0]=p+1;
								z[d][1]=q+1;
								d++;
							}
						}
					}
				}
				e=0;
				printf("%d\n",d);
			}
			if(x>47&&x<58)
			{
				e*=10;
				e+=x-48;
			}
		}
	}
	return 0;
}