#include<stdio.h>
char k[9][9],l[10],m[10][10],n[9],o,p,q[81][2];
int abcc(int w)
{
	int a,b,c,d,i,j,x,y,z[10];
	if(w==o)
	{
		p++;
		
		printf("Solution %d:\n",p);
		for(a=0;a<9;a++)
		{
			for(b=0;b<9;b++)
			{
				printf("%d ",k[a][b]);
			}
			printf("\n");
		}
		
		/*return 1;*/
	}
	for(a=1;a<10;a++)
	{
		z[a]=1;
	}
	i=q[w][0];
	j=q[w][1];
	for(x=0;x<9;x++)
	{
		if(k[x][j])
		{
			z[k[x][j]]=0;
		}
		if(k[i][x])
		{
			z[k[i][x]]=0;
		}
	}
	for(a=i-i%3,b=a+3,d=j-j%3+3;a<b;a++)
	{
		for(c=j-j%3;c<d;c++)
		{
			if(k[a][c])
			{
				z[k[a][c]]=0;
			}
		}
	}
	for(a=1;a<10;a++)
	{
		if(z[a])
		{
			k[i][j]=a;
			if(abcc(w+1)&&p==2)
			{/*
				return 1;
			*/}
			k[i][j]=0;
		}
	}
	return 0;
}
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
    g=0;
    while(scanf("%d",&k[0][0])==1)
    {
		o=0;
		if(!k[0][0])
		{
			q[0][0]=0;
			q[0][1]=0;
			o=1;
		}
        for(a=0,b=1;a<9;a++)
        {
            for(b;b<9;b++)
            {
                scanf("%d",&k[a][b]);
				if(!k[a][b])
				{
					q[o][0]=a;
					q[o][1]=b;
					o++;
				}
            }
            b=0;
        }
        for(a=0;a<9;a++)
        {
			for(b=1;b<10;b++)
            {
                l[b]=0;
            }
            for(b=0;b<9;b++)
            {
                if(k[a][b])
                {
                    if(l[k[a][b]])
                    {
                        break;
                    }
                    l[k[a][b]]=1;
                }
            }
            if(b<9)
            {
                break;
            }
        }
        if(a<9)
        {
			printf("Case %d: Illegal.\n",++g);
            continue;
        }
        for(a=0;a<9;a++)
        {
            for(b=1;b<10;b++)
            {
                l[b]=0;
            }
            for(b=0;b<9;b++)
            {
                if(k[b][a])
                {
                    if(l[k[b][a]])
                    {
                        break;
                    }
                    l[k[b][a]]=1;
                }
            }
            if(b<9)
            {
				break;
            }
        }
        if(a<9)
        {
            printf("Case %d: Illegal.\n",++g);
            continue;
        }
        for(a=0;a<9;a+=3)
        {
            for(b=0;b<9;b+=3)
            {
                for(c=1;c<10;c++)
                {
                    l[c]=0;
                }
                for(c=a,d=a+3,f=b+3;c<d;c++)
                {
                    for(e=b;e<f;e++)
                    {
                        if(k[c][e])
                        {
							if(l[k[c][e]])
                            {
                                break;
                            }
                            l[k[c][e]]=1;
                        }
                    }
                    if(e<f)
                    {
                        break;
                    }
                }
                if(c<d)
                {
                    break;
                }
            }
            if(b<9)
            {
                break;
            }
        }
		if(a<9)
        {
            printf("Case %d: Illegal.\n",++g);
            continue;
        }
		p=0;
		abcc(0);
		if(!p)
		{
			printf("Case %d: Impossible.\n",++g);
		}
		else if(p==1)
		{
			printf("Case %d: Unique.\n",++g);
		}
		else
		{
			printf("Case %d: Ambiguous.\n",++g);
		}
    }
    return 0;
}
