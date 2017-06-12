#include<stdio.h>
int main()
{
    int a[50],b,c,d,e,f,g,h,i=1,j;
    while(scanf("%d %d",&b,&c)==2)
    {
        for(d=0;d<b;d++)
        {
            a[d]=1;
        }
        for(d=0,j=0,h=b;d<20;d++)
        {
            scanf("%d",&e);
            if(h==c&&j==0)
            {
                printf("Selection #%d\n",i);
                i++;
                for(h=0,j=0;h<b;h++)
                {
                    if(a[h]==1)
                    {
                        if(j!=0)
                        {
                            printf(" ");
                        }
                        else
                        {
                            j++;
                        }
                        printf("%d",h+1);
                    }
                }
                j=1;
                printf("\n\n");
            }
            if(j==0)
            {
                for(f=0,g=0;f<b;f++)
                {
                    g+=a[f];
                    if(g==e)
                    {
                        g=0;
                        a[f]=0;
                        h--;
                        if(h==c)
                        {
                            printf("Selection #%d\n",i);
                            i++;
                            for(h=0,j=0;h<b;h++)
                            {
                                if(a[h]==1)
                                {
                                    if(j!=0)
                                    {
                                        printf(" ");
                                    }
                                    else
                                    {
                                        j++;
                                    }
                                    printf("%d",h+1);
                                }
                            }
                            j=1;
                            printf("\n\n");
                            break;
                        }
                    }
                }
                g=0;
            }
        }
        if(j==0)
        {
            printf("Selection #%d\n",i);
            i++;
            for(h=0;h<b;h++)
            {
                if(a[h]==1)
                {
                    if(j!=0)
                    {
                        printf(" ");
                    }
                    else
                    {
                        j++;
                    }
                    printf("%d",h+1);
                }
            }
            printf("\n\n");
        }
    }
    return 0;
}
