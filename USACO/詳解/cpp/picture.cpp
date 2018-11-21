/*
ID: dd.ener1
PROG: picture
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;


const int maxn=21000;
int N,res;

struct line{
	int x1,x2;
	int y;
	bool start;
}lx[maxn],ly[maxn];

void input(){
	freopen("picture.in","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		int x,y,X,Y;
		scanf("%d%d%d%d",&x,&y,&X,&Y);
		
		lx[i].x1=x+10000;
		lx[i].x2=X+10000;
		lx[i].y=y+10000;
		lx[i].start=true;

		lx[N+i].x1=x+10000;
		lx[N+i].x2=X+10000;
		lx[N+i].y=Y+10000;
		lx[N+i].start=false;
		
		ly[i].x1=y+10000;
		ly[i].x2=Y+10000;
		ly[i].y=x+10000;
		ly[i].start=true;

		ly[N+i].x1=y+10000;
		ly[N+i].x2=Y+10000;
		ly[N+i].y=X+10000;
		ly[N+i].start=false;
	}
	N*=2;
}
int compare(const void* a,const void* b){
	return ((line*)a)->y - ((line*)b)->y;
}
int compute(line* l){
	qsort(l,N,sizeof(line),compare);
	int cov[21000];
	memset(cov,0,sizeof(cov));
	int res=0;
	for(int i=0;i<N;++i){
		if(l[i].start)
			for(int k=l[i].x1;k<l[i].x2;++k){
				if(1==++cov[k])++res;
			}
		else
			for(int k=l[i].x1;k<l[i].x2;++k){
				if(0==--cov[k])++res;
			}
	}
	return res;
}
void solve(){
	res=compute(lx)+compute(ly);
}
void output(){
	freopen("picture.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	input();
	solve();
	output();
}
