#include<stdio.h>
int main()
{
    char a,b,e[6];
    int c,d=0,f=0,g,h,i[3];
    for(c=3;c>0;c--)
    {
        i[c-1]=0;
    }
    while(scanf("%c",&a)==1)
    {
        if(a==10)
        {
            if(e[0]=='e'&&e[1]=='/'&&e[2]=='o'&&e[3]=='/'&&e[4]=='i')
            {
                break;
            }
            if(i[0]!=5)
            {
                printf("1\n");
            }
            else
            {
                if(i[1]!=7)
                {
                    printf("2\n");
                }
                else
                {
                    if(i[2]!=5)
                    {
                        printf("3\n");
                    }
                    else
                    {
                        printf("Y\n");
                    }
                }
            }
            for(c=3;c>0;c--)
            {
                i[c-1]=0;
            }
            d=0;
            f=0;
        }
        else if(a=='/')
        {
            d=0;
            c++;
            if(f<5)
            {
                e[f]=a;
                f++;
            }
        }
        else
        {
            if(f<5)
            {
                e[f]=a;
                f++;
            }
            if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='y')
            {
                if(d==0)
                {
                    d++;
                    i[c]++;
                }
            }
            else
            {
                d=0;
            }
        }
    }
    return 0;
}
