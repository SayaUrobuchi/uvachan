/*
ID: dd.ener1
PROG: fence3
LANG: C++
*/

#include <cstdio>
#include <cmath>
using namespace std;

struct fence{
	double X,x,Y,y;//´ó¡¢Ð¡
	void input(){
		scanf("%lf %lf %lf %lf",&X,&Y,&x,&y);
		if(X<x){
			double t=X;
			X=x;
			x=t;
		}
		if(Y<y){
			double t=Y;
			Y=y;
			y=t;
		}
	}
	double dis(double i,double j){
		double xx=0,yy=0;
		if(i<x)
			xx=x-i;
		else if(i>X)
			xx=i-X;
		if(j<y)
			yy=y-j;
		else if(j>Y)
			yy=j-Y;
		return sqrt(xx*xx+yy*yy);
	}
}f[200];
int N;
double X,Y;
double best;

void input(){
	freopen("fence3.in","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<N;++i)
		f[i].input();
}
double total(){
	double res=0;
	for(int i=0;i<N;++i)
		res+=f[i].dis(X,Y);
	return res;
}
bool update(){
	double now=total();
	if(best>now){
		best=now;
		return true;
	}
	return false;
}
void shake(double d){
	int n=0,N=2000/d;
	for(;;){
		if(++n>N)break;
		X+=d;Y+=d;
		if(update())continue;
		else{
			X-=d;
			Y-=d;
		}
		X-=d;Y-=d;
		if(update())continue;
		else{
			X+=d;
			Y+=d;
		}
		X-=d;Y+=d;
		if(update())continue;
		else{
			X+=d;
			Y-=d;
		}
		X+=d;Y-=d;
		if(update())continue;
		else{
			X-=d;
			Y+=d;
		}
		X+=d;
		if(update())continue;
		else X-=d;
		X-=d;
		if(update())continue;
		else X+=d;
		Y+=d;
		if(update())continue;
		else Y-=d;
		Y-=d;
		if(update())continue;
		else Y+=d;
		break;
	}
}
void solve(){
	X=Y=0;
	best=total();
	shake(100);
	shake(10);
	shake(1);
	shake(0.1);
	shake(0.03);
}
void output(){
	freopen("fence3.out","w",stdout);
	printf("%.1lf %.1lf %.1lf\n",X,Y,best);
}
int main(){
	//freopen("fence3.log","w",stdout);
	input();
	solve();
	output();
}
