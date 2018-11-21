/*
ID: dd.ener1
PROG: rockers
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

const long maxN=20,maxM=20,maxT=20;
long N,M,T;
long time[maxN];
long f[maxN][maxM][maxT+1];//f[i][j][t]表示考虑到第i首歌，开了j张完整的盘，最后一张盘已经用了t分钟时能够录制的最多歌曲 
/*
f[i][j][t]=max{
	f[i][j][t-1],//为了保持单调性
	f[i-1][j][t],//不录第i首歌，前提是i!=0 
	f[i-1][j][t-time[i]]+1,//将第i首歌放到最后一张盘里，前提是t-time[t]>=0
	f[i-1][j-1][T]+t>=time[i]//新开一张盘，前面的歌都录在前一些盘里，前提是j!=0 
}
*/
void input(){
	freopen("rockers.in","r",stdin);
	scanf("%d%d%d",&N,&T,&M);
	for(long i=0;i<N;++i)
		scanf("%d",time+i);
}
void update(long& old,const long now){
	if(old<now)old=now;
}
void solve(long i,long j,long t){//调用此函数的前提是i!=0
	long& now=f[i][j][t];
	now=f[i-1][j][t];
	if(t!=0)update(now,f[i][j][t-1]);
	if(t>=time[i])update(now,f[i-1][j][t-time[i]]+1);
	if(j!=0)update(now,f[i-1][j-1][T]+(t>=time[i]));
}
void solve(){
	memset(f,0,sizeof(f));
	for(long j=0;j<M;++j)
		for(long t=0;t<=T;++t)
			f[0][j][t]=(t>=time[0]);
	for(long i=1;i<N;++i)
		for(long j=0;j<M;++j)
			for(long t=0;t<=T;++t)
				solve(i,j,t);
}
void output(){
	freopen("rockers.out","w",stdout);
	printf("%d\n",f[N-1][M-1][T]);
}
int main(){
	input();
	solve();
	output();
}
