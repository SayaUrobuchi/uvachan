/*
ID: dd.ener1
PROG: stall4
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

template<class T>
class queue{
	private:
		long N;
		T* s;
		long beg,end;
	public:
		inline void init(){
			beg=end=0;
		}
		queue(long size):N(size),s(new T[size]){
			init();
		}
		inline void push(const T& item){
			s[end]=item;
			++end;
			end%=N;
		}
		inline T pop(){
			T res=s[beg];
			++beg;
			beg%=N;
			return res;
		}
		inline bool empty(){
			return beg==end;
		}
		~queue(){
			delete[] s;
		}
};

const long maxn=410;

long N;
long u[maxn][maxn];//»¡ 
long next[maxn][maxn];
long pre[maxn];
bool vis[maxn];
long res;

void input(){
	memset(u,0,sizeof(u));
	freopen("stall4.in","r",stdin);
	long m;
	scanf("%d%d",&N,&m);
	for(long i=1;i<=N;++i){
		long l;
		scanf("%d",&l);
		for(long j=0;j<l;++j){
			long b;
			scanf("%d",&b);
			u[i][b+N]=1;
		}
		u[0][i]=1;
	}
	for(long i=1;i<=m;++i)
		u[N+i][N+m+1]=1;
	N+=m;++N;
}
void presolve(){
	memset(next,-1,sizeof(next));
	for(long k=0;k<=N;++k){
		long pre=0;
		for(long j=1;j<=N;++j){
			if(u[k][j]||u[j][k]){
				next[k][pre]=j;
				pre=j;
			}
		}
	}
}
void findway(){
	memset(pre,-1,sizeof(pre));
	memset(vis,0,sizeof(vis));
	queue<long> que(N+10);
	que.push(0);
	vis[0]=true;
	while(!que.empty()){
		long now=que.pop();
		for(long i=0;i!=-1;i=next[now][i]){
			if(u[now][i]&&!vis[i]){
				vis[i]=true;
				pre[i]=now;
				que.push(i);
			}
		}
	}
}
void solveway(){
	long least=1000000000;
	for(long now=N;now!=0;now=pre[now])
		if(u[pre[now]][now]<least)least=u[pre[now]][now];
	for(long now=N;now!=0;now=pre[now]){
		u[pre[now]][now]-=least;
		u[now][pre[now]]+=least;
	}
}
void solve(){
	res=0;
	presolve();
	for(;;){
		findway();
		if(!vis[N])break;
		solveway();
	}
	for(long i=0;i<N;++i)
		res+=u[N][i];
}
void output(){
	freopen("stall4.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	input();
	solve();
	output();
}
