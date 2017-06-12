#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[10050];
int abcc()
{
    e+=k[b]+k[b+1];
    if(e>d)
    {
        d=e;
    }
    if(b<c-1)
    {
        b+=2;
        abcc();
    }
    return 0;
}
int main()
{
    while(scanf("%d",&a)==1)
    {
        if(a==0)
        {
            break;
        }
        for(b=0,c=0;b<a;b++)
        {
            scanf("%d",&d);
            k[b]=0;
            if(d<0)
            {
                if(c!=0||k[c]!=0)
                {
                    if(c%2==0)
                    {
                        c++;
                    }
                    k[c]+=d;
                }
            }
            else
            {
                if(c%2!=0)
                {
                    c++;
                }
                k[c]+=d;
            }
        }
        if(c==0&&k[0]==0)
        {
            printf("Losing streak.\n");
        }
        else
        {
            for(i=1,j=-1;i<=c+1;i+=2)
            {
                b=i;
                e=k[i-1];
                d=e;
                //printf("%d\n",d);
                abcc();
                if(d>j)
                {
                    j=d;
                }
            }
            if(j<0)
            {
                printf("Losing streak.\n");
            }
            else
            {
                printf("The maximum winning streak is %d.\n",j);
            }
        }
    }
    return 0;
}
