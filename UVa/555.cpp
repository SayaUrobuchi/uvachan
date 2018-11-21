#include<stdio.h>
int main()
{
    char b;
    int a[4][13],c,d,e,f,g,h;
    while(scanf("%c",&b)==1)
    {
        if(b=='#')
        {
            break;
        }
        if(b=='N')
        {
            c=3;
        }
        else if(b=='E')
        {
            c=0;
        }
        else if(b=='S')
        {
            c=1;
        }
        else
        {
            c=2;
        }
        scanf("%c",&b);
        for(d=0;d<52;d++)
        {
            e=d+c;
            e%=4;
            f=d/4;
            if(d==26)
            {
                scanf("%c",&b);
            }
            scanf("%c",&b);
            if(b=='C')
            {
                a[e][f]=100;
            }
            else if(b=='D')
            {
                a[e][f]=200;
            }
            else if(b=='S')
            {
                a[e][f]=300;
            }
            else
            {
                a[e][f]=400;
            }
            scanf("%c",&b);
            if(b=='T')
            {
                a[e][f]+=10;
            }
            else if(b=='J')
            {
                a[e][f]+=11;
            }
            else if(b=='Q')
            {
                a[e][f]+=12;
            }
            else if(b=='K')
            {
                a[e][f]+=13;
            }
            else if(b=='A')
            {
                a[e][f]+=14;
            }
            else
            {
                a[e][f]+=b-48;
            }
        }
        for(c=0;c<4;c++)
        {
            for(d=0;d<12;d++)
            {
                for(e=0;e<12;e++)
                {
                    if(a[c][e]>a[c][e+1])
                    {
                        f=a[c][e];
                        a[c][e]=a[c][e+1];
                        a[c][e+1]=f;
                    }
                }
            }
        }
        for(c=0;c<4;c++)
        {
            if(c==0)
            {
                printf("S:");
            }
            else if(c==1)
            {
                printf("W:");
            }
            else if(c==2)
            {
                printf("N:");
            }
            else
            {
                printf("E:");
            }
            for(d=0;d<13;d++)
            {
                if(a[c][d]>400)
                {
                    printf(" H");
                }
                else if(a[c][d]>300)
                {
                    printf(" S");
                }
                else if(a[c][d]>200)
                {
                    printf(" D");
                }
                else
                {
                    printf(" C");
                }
                e=a[c][d]%100;
                if(e==14)
                {
                    printf("A");
                }
                else if(e==13)
                {
                    printf("K");
                }
                else if(e==12)
                {
                    printf("Q");
                }
                else if(e==11)
                {
                    printf("J");
                }
                else if(e==10)
                {
                    printf("T");
                }
                else
                {
                    printf("%d",e);
                }
            }
            printf("\n");
        }
        scanf("%c",&b);
    }
    return 0;
}
