/*
ID: dd.ener1
PROG: fence6
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

long N;
const long maxn=110;
long adj[maxn][2][maxn];//adj[i][0]和adj[i][1]分别是输入的两套边表
long edges[maxn][2];//边数
long stamp[maxn][2];//每条边的两个端点的真实编号 
long len[maxn];
long matrix[maxn][maxn];//表示两个篱笆交汇是在第一个篱笆的哪个边表 
long g[maxn*2][maxn*2];
long g2[maxn*2][maxn*2];
long n;
long best;

void input(){
	freopen("fence6.in","r",stdin);
	scanf("%d",&N);
	for(long i=0;i<N;++i){
		long n;
		scanf("%d",&n);
		scanf("%d%d%d",&len[n],&edges[n][0],&edges[n][1]);
		for(long j=0;j<edges[n][0];++j){
			scanf("%d",&adj[n][0][j]);
			matrix[n][adj[n][0][j]]=0;
		}
		for(long j=0;j<edges[n][1];++j){
			scanf("%d",&adj[n][1][j]);
			matrix[n][adj[n][1][j]]=1;
		}
	}
}
void makestamp(long k,bool side,long n){
	stamp[k][side]=n;
	for(long j=0;j<edges[k][side];++j){
		long now=adj[k][side][j];
		if(matrix[now][k]==0)stamp[now][0]=n;
		else stamp[now][1]=n;
	}
}
void makegraph(){
	n=0;
	memset(stamp,-1,sizeof(stamp));
	for(long i=1;i<=N;++i){
		if(stamp[i][0]==-1)makestamp(i,0,n++);
		if(stamp[i][1]==-1)makestamp(i,1,n++);
	}
	for(long i=0;i<n;++i)
		for(long j=0;j<n;++j)
			g[i][j]=10000000;
	for(long i=1;i<=N;++i)
		g[stamp[i][0]][stamp[i][1]]=g[stamp[i][1]][stamp[i][0]]=len[i];
}
void update(long& old,long now){
	if(now<old)old=now;
}
void floyd(){
	best=10000000;
	for(long i=0;i<n;++i)
		for(long j=0;j<n;++j)
			g2[i][j]=g[i][j];
	for(long k=0;k<n;++k){
		for(long i=0;i<k;++i)
			for(long j=0;j<n;++j){
				if(j==i||j==k)continue; 
				update(best,g[i][k]+g[k][j]+g2[j][i]);
				update(best,g[j][k]+g[k][i]+g2[i][j]);
			}
		for(long i=0;i<n;++i)
			for(long j=0;j<n;++j)
				update(g2[i][j],g2[i][k]+g2[k][j]);
	}
}
void output(){
	freopen("fence6.out","w",stdout);
	printf("%d\n",best);
}
int main(){
	//freopen("fence6.log","w",stdout);
	input();
	makegraph();
	floyd();
	output();
}
