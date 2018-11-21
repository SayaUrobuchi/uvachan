/*
ID: dd.ener1
PROG: rect1
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

struct rect{
	long l,r;
	long u,d;
	long c;
};
rect rt[1010];
long color[2510];
long A,B,N;
void input(){
	freopen("rect1.in","r",stdin);
	scanf("%d%d%d",&A,&B,&N);
	rt[0].l=rt[0].u=0;
	rt[0].r=A;rt[0].d=B;
	for(long i=1;i<=N;++i){
		scanf("%d%d%d%d%d",&rt[i].l,&rt[i].u,&rt[i].r,&rt[i].d,&rt[i].c);
		--rt[i].c;
	}
	memset(color,0,sizeof(color));
}
void solve(long l,long r,long u,long d,long c,long k){
	while(k<=N&&(rt[k].l>=r||rt[k].r<=l||rt[k].u>=d||rt[k].d<=u))++k;
	if(k>N){
		color[c]+=(r-l)*(d-u);
		return;
	}
	if(rt[k].l>l){
		solve(l,rt[k].l,u,d,c,k+1);
		l=rt[k].l;
	}
	if(rt[k].r<r){
		solve(rt[k].r,r,u,d,c,k+1);
		r=rt[k].r;
	}
	if(rt[k].u>u)
		solve(l,r,u,rt[k].u,c,k+1);
	if(rt[k].d<d)
		solve(l,r,rt[k].d,d,c,k+1);
}
void solve(){
	for(long i=N;i>=0;--i)
		solve(rt[i].l,rt[i].r,rt[i].u,rt[i].d,rt[i].c,i+1);
}
void output(){
	freopen("rect1.out","w",stdout);
	for(long i=0;i<2500;++i){
		if(!color[i])continue;
		printf("%d %d\n",i+1,color[i]);
	}
}
int main(){
	input();
	solve();
	output();
}
