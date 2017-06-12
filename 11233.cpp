#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ary[20][2][30];

int comp(const void *p, const void *q)
{
  return strcmp((char*)p, (char*)q);
}

char son(char ch)
{
  if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
  {
    return 0;
  }
  return 1;
}

int bisearch(char* target, int left, int right)
{
  int center, cmp;
  if(left > right)
  {
    return 0;
  }
  center = (left + right) / 2;
  cmp = strcmp((char*)ary[center], target);
  if(!cmp)
  {
    return center+1;
  }
  else if(cmp > 0)
  {
    return bisearch(target, left, center-1);
  }
  else
  {
    return bisearch(target, center+1, right);
  }
}

int main()
{
  int i, len, index, l, n;
  char buf[30], last, slast;
  scanf("%d%d", &l, &n);
  for(i=0; i<l; i++)
  {
    scanf("%s%s", ary[i][0], ary[i][1]);
  }
  qsort(ary, l, sizeof(ary[0]), comp);
  for(i=0; i<n; i++)
  {
    scanf("%s", buf);
    index = bisearch(buf, 0, l-1);
    if(index)
    {
      printf("%s\n", ary[index-1][1]);
    }
    else
    {
      len = strlen(buf) - 1;
      last = buf[len];
      slast = len ? buf[len-1] : 0;
      if(last == 'y' && son(slast))
      {
        buf[len] = 0;
        strcat(buf, "ies");
      }
      else if(last == 'o' || last == 'x' || last == 's' || (last == 'h' && (slast == 's' || slast == 'c')))
      {
        strcat(buf, "es");
      }
      else
      {
        strcat(buf, "s");
      }
      printf("%s\n", buf);
    }
  }
  return 0;
}
