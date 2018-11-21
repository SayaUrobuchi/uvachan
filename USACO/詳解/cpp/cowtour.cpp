/*
ID: dd.ener1
PROG: cowtour
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const long maxn=160;
const double OO=100000.0;
struct point{
	long x,y;
};
long N;
point ps[maxn];
bool conn[maxn][maxn];
double dis[maxn][maxn];
double ldis[maxn];
long mark[maxn];//表示从属于第几个牧场
double mldis[maxn];

void input(){
	freopen("cowtour.in","r",stdin);
	scanf("%d\n",&N);
	for(long i=0;i<N;++i)
		scanf("%d %d\n",&ps[i].x,&ps[i].y);
	for(long i=0;i<N;++i){
		for(long j=0;j<N;++j)
			conn[i][j]=(getchar()=='1');
		getchar();//ignore '\n'
	}
	for(long i=0;i<N;++i)conn[i][i]=true;
}
inline double squa(const double& d){
	return d*d;
}
inline double getdis(long i,long j){
	return sqrt(squa(ps[i].x-ps[j].x)+squa(ps[i].y-ps[j].y));
}
void solvedis(){
	for(long i=0;i<N;++i)
		for(long j=0;j<N;++j)
			dis[i][j]=conn[i][j]?getdis(i,j):OO;
	for(long k=0;k<N;++k)
		for(long i=0;i<N;++i)
			for(long j=0;j<N;++j)
				if(dis[i][k]+dis[k][j]<dis[i][j])dis[i][j]=dis[i][k]+dis[k][j];
}
void solveldis(){
	for(long i=0;i<N;++i){
		ldis[i]=0;
		for(long j=0;j<N;++j){
			if(i==j)continue;
			if(dis[i][j]==OO)continue;
			if(dis[i][j]>ldis[i])
				ldis[i]=dis[i][j];
		}
	}
}
void solvemark(){
	memset(mark,-1,sizeof(mark));
	for(long i=0;i<N;++i){
		if(mark[i]!=-1)continue;
		mark[i]=i;
		for(long j=i+1;j<N;++j)
			if(dis[i][j]!=OO)mark[j]=i;
	}
}
void solvemldis(){
	for(long i=0;i<N;++i){
		mldis[i]=0;
		if(mark[i]!=i)continue;
		for(long j=i;j<N;++j){
			if(mark[j]!=i)continue;
			if(ldis[j]>mldis[i])mldis[i]=ldis[j];
		}
	}
}
inline const double& max(const double& a,const double& b){
	return a>b?a:b;
}
double solve(){
	solvedis();
	solveldis();
	solvemark();
	solvemldis();
	double res=OO;
	for(long i=0;i<N;++i)
		for(long j=i+1;j<N;++j){
			if(mark[i]==mark[j])continue;
			double res1=max(mldis[mark[i]],mldis[mark[j]]);
			double res2=ldis[i]+ldis[j]+getdis(i,j);
			double now=max(res1,res2);
			if(now<res)res=now;
		}
	return res;
}
void output(const double& res){
	freopen("cowtour.out","w",stdout);
	printf("%.6f\n",res);
}
int main(){
	input();
	output(solve());
}
