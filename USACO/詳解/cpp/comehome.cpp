/*
ID: dd.ener1
PROG: comehome
LANG: C++
*/
#include <cstdio>
using namespace std;

const long N=52;
const long OO=1000000000;
long g[N][N];
long dis[N];
bool vis[N];

long chr2num(char c){
	if('a'<=c&&c<='z')return c-'a';
	return c-'A'+26;
}
void input(){
	freopen("comehome.in","r",stdin);
	long m;
	scanf("%d\n",&m,stdin);
	for(long i=0;i<N;++i)
		for(long j=0;j<N;++j)
			g[i][j]=OO;
	do{
		char c1,c2;
		long dis;
		scanf("%c %c %d\n",&c1,&c2,&dis);
		long p1=chr2num(c1);
		long p2=chr2num(c2);
		if(dis<g[p1][p2])g[p1][p2]=g[p2][p1]=dis;
	}while(--m);
}
void solve(long src){
	for(long i=0;i<N;++i){
		dis[i]=OO;
		vis[i]=false;
	}
	dis[src]=0;
	for(;;){
		long v=-1;
		long min=OO;
		for(long i=0;i<N;++i){
			if(vis[i])continue;
			if(dis[i]<min){
				v=i;
				min=dis[i];
			}
		}
		if(v==-1)break;
		vis[v]=true;
		for(long k=0;k<N;++k){
			if(vis[k])continue;
			if(dis[v]+g[v][k]<dis[k])dis[k]=dis[v]+g[v][k];
		}
	}
}
void output(){
	freopen("comehome.out","w",stdout);
	long res;
	long min=OO;
	for(long i=26;i<N-1;++i)
		if(dis[i]<min){
			res=i;
			min=dis[i];
		}
	printf("%c %d\n",'A'+res-26,min);
}
int main(){
	input();
	solve(51);
	output();
}
