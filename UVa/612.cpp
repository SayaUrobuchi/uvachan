#include<stdio.h>
int main()
{
    char i,j[100][102],s;
    int a,b,c,d,e,f,g,h[100][2],k;
		s=0;
    scanf("%d",&a);
    for(a;a>0;a--)
    {
			if(s)
			{
				printf("\n");
			}
			s=1;
      scanf("%d %d%c",&b,&c,&i);
      for(d=0;d<c;d++)
      {
        h[d][1]=d;
        h[d][0]=0;
        for(e=0;e<b;e++)
        {
          scanf("%c",&j[d][e]);
        }
        scanf("%c",&i);
      }
      for(d=0;d<c;d++)
      {
        for(e=0;e<b-1;e++)
        {
          for(f=e+1;f<b;f++)
          {
            if(j[d][e]>j[d][f])
            {
              h[d][0]++;
            }
          }
        }
      }
      for(d=0;d<c-1;d++)
      {
        for(e=0;e<c-1;e++)
        {
          if(h[e][0]>h[e+1][0])
          {
            f=h[e][0];
            h[e][0]=h[e+1][0];
            h[e+1][0]=f;
            f=h[e][1];
            h[e][1]=h[e+1][1];
            h[e+1][1]=f;
          }
        }
      }
      for(d=0;d<c;d++)
      {
        g=h[d][1];
        for(e=0;e<b;e++)
        {
          printf("%c",j[g][e]);
        }
        printf("\n");
      }
  	}
    return 0;
}