#include<stdio.h>
#include<string.h>
int main()
{
    char k[101][101],x;
    int a,b,c,d,e,f,g,i[101],j;
    for(a=0;a<101;a++)
    {
        i[a]=0;
    }
    a=0;
    j=0;
    while(gets(k[a]))
    {
        if(strcmp(k[a],"EOF")==0)
        {
            break;
        }
        i[a]=strlen(k[a]);
        if(i[a]>j)
        {
            j=i[a];
        }
        a++;
    }
    for(b=0;b<j;b++)
    {
        for(c=a-1,d=0;c>=0;c--)
        {
            if(i[c]<=b)
            {
                d++;
            }
            else
            {
                if(d!=0)
                {
                    for(d;d>0;d--)
                    {
                        printf(" ");
                    }
                }
                printf("%c",k[c][b]);
            }
        }
        printf("\n");
    }
    //while(1);
    return 0;
}
