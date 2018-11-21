/*
ID: dd.ener1
PROG: fence4
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

struct point{
	point(){}
	point(double _x,double _y):x(_x),y(_y){}
	double x,y;
};
point observer;
point fence[200];
bool can[200];
long N;

void input(){
	freopen("fence4.in","r",stdin);
	scanf("%d",&N);
	scanf("%lf%lf",&observer.x,&observer.y);
	for(long i=0;i<N;++i)
		scanf("%lf%lf",&fence[i].x,&fence[i].y);
}
double cross(point a,point b,point c){
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int dblcmp(double d){
	const double zero1=0.000001,zero2=-0.000001;
	if(d>zero1)return 1;
	if(d<zero2)return -1;
	return 0;
}
double dot(point a,point b,point c){
	return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
}
int betweenCmp(const point& a,const point& b,const point& c){
	return dblcmp(dot(a,b,c));
}
point crosspoint;
long segcross(point a,point b,point c,point d,point& p=crosspoint){//a和b一条线段，c和d一条线段
	double s1,s2,s3,s4;
	long d1=dblcmp(s1=cross(a,b,c));
	long d2=dblcmp(s2=cross(a,b,d));
	long d3=dblcmp(s3=cross(c,d,a));
	long d4=dblcmp(s4=cross(c,d,b));
	if(d1*d2<0&&d3*d4<0){
		p.x=(c.x*s2-d.x*s1)/(s2-s1);
		p.y=(c.y*s2-d.y*s1)/(s2-s1);
		return 1;
	}
	if((d1==0&&betweenCmp(c,a,b)<=0)||
		(d2==0&&betweenCmp(d,a,b)<=0)||
		(d3==0&&betweenCmp(a,c,d)<=0)||
		(d4==0&&betweenCmp(b,c,d)<=0))
		return 2;
	return 0;
}
bool valid(){
	for(long k=0;k<=N;++k)
		for(long j=k+2;j<=N;++j)
			if(segcross(fence[k%N],fence[(k+1)%N],fence[j%N],fence[(j+1)%N])==1)
				return false;
	return true;
}
point mid(const point &a,const point &b){
	return point((a.x+b.x)/2,(a.y+b.y)/2);
}
inline double sqr(double a){
	return a*a;
}
inline double sqrdis(const point &a,const point &b){
	return sqr(a.x-b.x)+sqr(a.y-b.y);
}
long first_see(const point &d){
	const double OO=1e20;
	double near=OO;
	long res=N;
	for(long i=0;i<N;++i){
		long seg=segcross(observer,d,fence[i],fence[i+1==N?0:i+1]);
		if(seg==1){
			double now=sqrdis(observer,crosspoint);
			if(now<near){
				near=now;
				res=i;
			}
		}
		if(seg==2)return N;
	}
	return res;
}
inline point shake(const point& p,long way){
	const double delta=0.001;
	switch(way){
		case 0:
			return point(p.x-delta,p.y);
		case 1:
			return point(p.x+delta,p.y);
		case 2:
			return point(p.x,p.y-delta);
		case 3:
			return point(p.x,p.y+delta);
		case 4:
			return point(p.x-delta,p.y-delta);
		case 5:
			return point(p.x-delta,p.y+delta);
		case 6:
			return point(p.x+delta,p.y+delta);
		case 7:
			return point(p.x+delta,p.y-delta);
	}
}
void solve(){
	memset(can,0,sizeof(can));
	for(long i=0;i<N;++i){
		for(long k=0;k<8;++k){
			can[first_see(shake(fence[i],k))]=true;
			can[first_see(shake(mid(fence[i],fence[i+1==N?0:i+1]),k))]=true;
		}
	}
}
void output(bool b){
	freopen("fence4.out","w",stdout);
	if(!b)puts("NOFENCE");
	else{
		long res=0;
		for(long i=0;i<N;++i)
			if(can[i])++res;
		printf("%d\n",res);
		for(long i=0;i<N-2;++i)
			if(can[i])
				printf("%.0f %.0f %.0f %.0f\n",fence[i].x,fence[i].y,fence[i+1].x,fence[i+1].y);
		if(can[N-1])
			printf("%.0f %.0f %.0f %.0f\n",fence[0].x,fence[0].y,fence[N-1].x,fence[N-1].y);
		if(can[N-2])
			printf("%.0f %.0f %.0f %.0f\n",fence[N-2].x,fence[N-2].y,fence[N-1].x,fence[N-1].y);
	}
}
int main(){
	freopen("fence4.log","w",stdout);
	input();
	if(!valid()){
		output(false);
		return 0;
	}
	solve();
	output(true);
	return 0;
}
