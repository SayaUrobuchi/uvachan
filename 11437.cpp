#include <stdio.h>

double ab(double t)
{
	return t>0 ? t : -t;
}

double cross(double x1, double y1, double x2, double y2)
{
	return x1*y2-y1*x2;
}

int main()
{
	int count;
	double ax, ay, bx, by, cx, cy, dx, dy, ex, ey, fx, fy, px, py, qx, qy, rx, ry, rat, res;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy);
		dx = bx + (cx-bx)/3;
		dy = by + (cy-by)/3;
		ex = cx + (ax-cx)/3;
		ey = cy + (ay-cy)/3;
		fx = ax + (bx-ax)/3;
		fy = ay + (by-ay)/3;
		rat = ab(cross(dx-ax, dy-ay, bx-ax, by-ay)/cross(dx-ax, dy-ay, ex-bx, ey-by));
		px = ax + (dx-ax)*rat;
		py = ay + (dy-ay)*rat;
		rat = ab(cross(ex-bx, ey-by, cx-bx, cy-by)/cross(cx-fx, cy-fy, bx-ex, by-ey));
		qx = bx + (ex-bx)*rat;
		qy = by + (ey-by)*rat;
		rat = ab(cross(fx-cx, fy-cy, ax-cx, ay-cy)/cross(dx-ax, dy-ay, cx-fx, cy-fy));
		rx = cx + (fx-cx)*rat;
		ry = cy + (fy-cy)*rat;
		res = ab(px * qy + qx * ry + rx * py - py * qx - qy * rx - ry * px);
		res /= 2;
		printf("%.0lf\n", res);
	}
	return 0;
}
