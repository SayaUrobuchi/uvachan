#include<stdio.h>
#include<string.h>
int main()
{
    char w,x,y,z[20];
    int a,b,c,d,e,f,g,h,i[101],j[101][10],k[101][2];
    while(scanf("%d%c%c",&h,&x,&y)==3)
    {
        for(h;h>0;h--)
        {
            for(b=1;b<101;b++)
            {
                k[b][0]=-1;
                k[b][1]=0;
                for(c=1;c<10;c++)
                {
                    j[b][c]=0;
                }
            }
            while(gets(z))
            {
                if(strlen(z)==0)
                {
                    break;
                }
                sscanf(z,"%d %d %d%c%c%c",&b,&c,&d,&y,&x,&w);
                if(k[b][0]==-1)
                {
                    k[b][0]++;
                }
                if(x=='I')
                {
                    if(j[b][c]>=0)
                    {
                        j[b][c]++;
                    }
                }
                else if(x=='C')
                {
                    if(j[b][c]>=0)
                    {
                        k[b][1]+=d;
                        k[b][1]+=j[b][c]*20;
                        j[b][c]=-1;
                        k[b][0]++;
                    }
                }
            }
            for(a=1,b=1;a<101;a++)
            {
                if(k[a][0]>=0)
                {
                    i[b]=a;
                    b++;
                }
            }
            d=b;
            for(a=1;a<d-1;a++)
            {
                for(b=1,c=0;b<d-1;b++)
                {
                    if(k[i[b]][0]<k[i[b+1]][0])
                    {
                        f=i[b];
                        i[b]=i[b+1];
                        i[b+1]=f;
                        c++;
                    }
                    else if(k[i[b]][0]==k[i[b+1]][0])
                    {
                        if(k[i[b]][1]>k[i[b+1]][1])
                        {
                            f=i[b];
                            i[b]=i[b+1];
                            i[b+1]=f;
                            c++;
                        }
                    }
                }
                if(c==0)
                {
                    break;
                }
            }
            if(g==1)
            {
                printf("\n");
            }
            for(a=1;a<d;a++)
            {
                printf("%d %d %d\n",i[a],k[i[a]][0],k[i[a]][1]);
            }
            g=1;
        }
    }
    return 0;
}
