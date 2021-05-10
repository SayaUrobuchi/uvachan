#include <iostream>

bool jc(double x, double y, double cx, double cy, double cr)
{
	return (x-cx)*(x-cx) + (y-cy)*(y-cy) <= cr*cr;
}

int main()
{
	int count, n, i;
	double x, y, w, h, r, mx, my;
	bool ok;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%lf%lf%lf%lf%lf%d", &x, &y, &w, &h, &r, &n);
		for (i=0; i<n; i++)
		{
			scanf("%lf%lf", &mx, &my);
			ok = false;
			if (mx >= x+r && mx <= x+w-r)
			{
				if (my >= y && my <= y+h)
				{
					ok = true;
				}
			}
			else if (my >= y+r && my <= y+h-r)
			{
				if (mx >= x && mx <= x+w)
				{
					ok = true;
				}
			}
			else
			{
				ok = ( jc(mx, my, x+r, y+r, r) || jc(mx, my, x+w-r, y+r, r)
					|| jc(mx, my, x+r, y+h-r, r) || jc(mx, my, x+w-r, y+h-r, r));
			}
			puts(ok ? "inside" : "outside");
		}
		puts("");
	}
	return 0;
}
