#include<stdio.h>
int main()
{
    char a;
    int b,c,d,e,f;
    scanf("%d%c",&e,&a);
    for(e;e>0;e--)
    {
        for(a=0,b=0,c=0,d=0,f=0;a!=100;a)
        {
            scanf("%c",&a);
            if(a==10)
            {
                if(f!=1&&b==0&&c==0)
                {
                    printf("Yes\n");
                }
                else
                {
                    printf("No\n");
                }
                break;
            }
            if(a==41)
            {
                if(b==0||d==0||d==91)
                {
                    f=1;
                    d=a;
                }
                else
                {
                    b--;
                    d=41;
                }
            }
            else if(a==93)
            {
                if(c==0||d==0||d==40)
                {
                    f=1;
                    d=a;
                }
                else
                {
                    c--;
                    d=93;
                }
            }
            else if(a!=10)
            {
                d=a;
                if(d>50)
                {
                    c++;
                }
                else
                {
                    b++;
                }
            }
        }
    }
    return 0;
}
