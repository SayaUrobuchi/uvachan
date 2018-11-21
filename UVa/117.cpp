#include <stdio.h>
#include <string.h>

char path[26][26];

int main()
{
  int i, j, k, ans, node[26], start, target, dp[26], dis[26], tmp1, tmp2, len, count;
  char str[100];
  i = 0;
  ans = 0;
  memset(node, 0, 26*4);
  memset(path, 0, 676);
  while(gets(str))
  {
    if(!strcmp(str, "deadend"))
    {
      for(j=0, start=-1, count=0; j<26; j++)
      {
        if(node[j] % 2)
        {
          if(start>-1)
          {
            target = j;
            break;
          }
          else start = j;
        }
      }
      for(j=0; j<26; j++)
    		if(node[j]) count++;
      if(start > -1)
      {
        memset(dp, 0, 26*4);
        dp[start] = 0;
        for(i=0; i<26; i++)
        {
					dis[i] = path[start][i];
				}
				dis[start] = -1;
        while(--count)
        {
          for(i=0, tmp1=0; i<26; i++)
          {
						if(dis[i] < 1) continue;
						if(!tmp1 || dis[i] < tmp1)
						{
							tmp1 = dis[i];
							tmp2 = i;
						}
          }
          i = tmp2;
          dp[i] = dis[i];
          dis[i] = -1;
          for(j=0; j<26; j++)
          {
						if(path[i][j] && (!dis[j] || dp[i] + path[i][j] < dis[j]))
						{
							dis[j] = path[i][j] + dp[i];
						}
					}
        }
        printf("%d\n", ans + dp[target]);
      }
      else printf("%d\n", ans);
      i = 0;
      ans = 0;
      memset(node, 0, 26*4);
      memset(path, 0, 676);
    }
    else
    {
      len = strlen(str);
      ans += len;
      tmp1 = str[0] - 97;
      tmp2 = str[len - 1] - 97;
      if(!path[tmp1][tmp2]) i++;
      if(!path[tmp1][tmp2] || path[tmp1][tmp2] > len)
      {
        path[tmp1][tmp2] = len;
        path[tmp2][tmp1] = len;
      }
      node[tmp1]++;
      node[tmp2]++;
    }
  }
  return 0;
}
