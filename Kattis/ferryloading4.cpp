#include <iostream>
using namespace std;

const int LEFT = 0;
const int RIGHT = 1;
const int SID = 2;
const int N = 10005;

int cnt[SID], cur[SID], car[SID][N];
char str[8];

int main()
{
	int count, n, len, i, l, side, weight, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &len, &n);
		len *= 100;
		cnt[LEFT] = cnt[RIGHT] = 0;
		cur[LEFT] = cur[RIGHT] = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d%s", &l, str);
			if (*str == 'l')
			{
				side = LEFT;
			}
			else
			{
				side = RIGHT;
			}
			car[side][cnt[side]] = l;
			++cnt[side];
		}
		for (side=LEFT, ans=0; cur[LEFT]<cnt[LEFT]||cur[RIGHT]<cnt[RIGHT]; ans++, side=LEFT+RIGHT-side)
		{
			for (weight=0; cur[side]<cnt[side]&&weight+car[side][cur[side]]<=len; 
				weight+=car[side][cur[side]], cur[side]++);
		}
		printf("%d\n", ans);
	}
	return 0;
}