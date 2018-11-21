#include <stdio.h>
#include <string.h>

bool x[35][35][35][35];
int ch[8][8][2],y[6];
int bfs[850000][6];

int main()
{
    int n,k,i,j,t,l,a,b,c,d;
    char z[2000];
    
    while(scanf("%d",&n)==1)
    {
        scanf("%d %d",&k,&i);
        memset(x,0,sizeof(x));
        memset(ch,0,sizeof(ch));
        
        for(i=1;i<=5;i++)
        {
            y[i]=0;
        }
        
        gets(z);
        l=strlen(z);
        j=0;
        a=0;
        b=0;
        for(i=0;i<=l;i++)
        {
            if(z[i]>=48 && z[i]<=57)
            {
                if(a==0)
                {
                    a=1;
                    b=z[i]-48;
                }
                else
                {
                    b*=10;
                    b+=z[i]-48;
                }
            }
            else
            {
                if(a!=0)
                {
                    j++;
                    y[j]=b;
                    a=0;
                    b=0;
                }
            }
            
            if(j==k)
            {
                break;
            }
        }
        
        x[y[1]][y[2]][y[3]][y[4]]=1;
        
        t=0;
        a=i;
        j=0;
        for(i=a;i<l;i++)
        {
            if(z[i]>=48 && z[i]<=57)
            {
				while(z[i]-48>k);
                ch[t][z[i]-48][1-j/2]++;
                j++;
            }
            if(j==4)
            {
                j=0;
                t++;
            }
        }
        
        i=1;
        for(j=1;j<=5;j++)
        {
            bfs[1][j]=y[j];
        }
        
        for(j=1;j<=i;j++)
        {
            for(a=1;a<=5;a++)
            {
                y[a]=bfs[i][a];
            }
            
            for(a=0;a<t;a++)
            {
                if(y[1]>=ch[a][1][0] && y[2]>=ch[a][2][0] && y[3]>=ch[a][3][0] && y[4]>=ch[a][4][0] && y[5]>=ch[a][5][0])
                {
                    for(b=1;b<=5;b++)
                    {
                        y[b]-=ch[a][b][0];
                        y[b]+=ch[a][b][1];
                    }
                    
                    if(x[y[1]][y[2]][y[3]][y[4]]==0)
                    {
                        i++;
                        x[y[1]][y[2]][y[3]][y[4]]=1;
                        for(b=1;b<=5;b++)
                        {
                            bfs[i][b]=y[b];
                        }
                    }
                    
                    for(b=1;b<=5;b++)
                    {
                        y[b]+=ch[a][b][0];
                        y[b]-=ch[a][b][1];
                    }
                }
            }
        }

        gets(z);
        l=strlen(z);
        y[1]=y[2]=y[3]=y[4]=y[5]=0;
        j=0;
        a=0;
        b=0;
        c=0;
        for(i=0;i<=l;i++)
        {
            if(z[i]>=48 && z[i]<=57)
            {
                if(a==0)
                {
                    a=1;
                    b=z[i]-48;
                }
                else
                {
                    b*=10;
                    b+=z[i]-48;
                }
            }
            else
            {
                if(a!=0)
                {
                    j++;
                    y[j]=b;
                    a=0;
                    b=0;
                }
            }
            
            if(j==k)
            {
                if(c!=0) printf(" ");
                printf("%d",x[y[1]][y[2]][y[3]][y[4]]);
                c++;
                j=0;
            }
        }
        printf("\n");
    }
    
    return 0;
}
