#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int team[1000000];
struct link
{
  int num;
  link *next;
};
link *tptr[1000], *ttail[1000], *ptr, *tmp2;

int main()
{
  int cas, i, j, tnum, in, p[1000], rp[1000], pnow, ptail, tmp;
  char str[10];
  cas=0;
  while(scanf("%d", &tnum)==1)
  {
    if(!tnum) break;
    printf("Scenario #%d\n", ++cas);
    for(i=0; i<tnum; i++)
    {
      scanf("%d", &j);
      while(j--)
      {
        scanf("%d", &in);
        team[in]=i;
      }
    }
    memset(p, -1, tnum*4);
    pnow=0;
    ptail=0;
    while(scanf("%s", str)==1)
    {
      if(str[0]=='S') break;
      if(str[0]=='E')
      {
        scanf("%d", &in);
        tmp=team[in];
        if(p[tmp]==-1)
        {
          p[tmp]=ptail;
          rp[ptail]=tmp;
          tptr[ptail]=(link*)malloc(sizeof(link));
          tptr[ptail]->num=in;
          tptr[ptail]->next=NULL;
          ttail[ptail]=tptr[ptail];
          ptail++;
          if(ptail==1000) ptail=0;
        }
        else
        {
          tmp=p[tmp];
          ttail[tmp]->next=(link*)malloc(sizeof(link));
          ttail[tmp]=ttail[tmp]->next;
          ttail[tmp]->num=in;
          ttail[tmp]->next=NULL;
        }
      }
      else
      {
        printf("%d\n", tptr[pnow]->num);
        ptr=tptr[pnow];
        tptr[pnow]=tptr[pnow]->next;
        free(ptr);
        if(tptr[pnow]==NULL)
        {
          p[rp[pnow]]=-1;
          pnow++;
          if(pnow==1000) pnow=0;
        }
      }
    }
    for(i=0; i<1000; i++)
    {
      ptr=tptr[i];
      while(ptr!=NULL)
      {
        tmp2=ptr;
        ptr=ptr->next;
        free(tmp2);
      }
    }
    printf("\n");
  }
  return 0;
}
