/*
ID: dd.ener1
PROG: telecow
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

template<class T>
class queue{
	private:
		int N;
		T* s;
		int beg,end;
	public:
		inline void init(){
			beg=end=0;
		}
		queue(int size):N(size),s(new T[size]){
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

const int maxn=256;
const int INF=65536;
int N,C1,C2;
bool s[maxn][maxn];//原相连关系 
int u[maxn][maxn];//网络流的图 
long next[maxn][maxn];
int res;
bool del[maxn];

void input(){
	memset(s,0,sizeof(s));
	freopen("telecow.in","r",stdin);
	int m;
	scanf("%d%d%d%d",&N,&m,&C1,&C2);
	for(int i=0;i<m;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		s[a][b]=true;
	}
	C1+=N;
}
void makegraph(){
	memset(u,0,sizeof(u));
	//每个点n拆成两个点：n和n+N
	//源点是C1+N，汇点是C2
	for(int i=1;i<=N;++i){
		u[i][i+N]=u[i+N][i]=!del[i];
		for(int j=1;j<=N;++j)
			if(s[i][j])
				u[i+N][j]=u[j+N][i]=INF;
	}
}
void makenext(){
	memset(next,-1,sizeof(next));
	for(long k=0;k<=N*2;++k){
		long pre=0;
		for(long j=1;j<=N*2;++j){
			if(u[k][j]||u[j][k]){
				next[k][pre]=j;
				pre=j;
			}
		}
	}
}

long pre[maxn];
bool vis[maxn];

void findway(){
	memset(pre,-1,sizeof(pre));
	memset(vis,0,sizeof(vis));
	queue<int> que(maxn);
	que.push(C1);
	vis[C1]=true;
	while(!que.empty()){
		int now=que.pop();
		for(int i=0;i!=-1;i=next[now][i]){
			if(u[now][i]&&!vis[i]){
				vis[i]=true;
				pre[i]=now;
				que.push(i);
			}
		}
	}
}
int solveway(){
	int least=1000000000;
	for(int now=C2;now!=C1;now=pre[now])
		if(u[pre[now]][now]<least)least=u[pre[now]][now];
	for(int now=C2;now!=C1;now=pre[now]){
		u[pre[now]][now]-=least;
		u[now][pre[now]]+=least;
	}
	return least;
}
int flow(){
	int res=0;
	for(;;){
		findway();
		if(!vis[C2])break;
		res+=solveway();
	}
	return res;
}
void solve(){
	makegraph();
	makenext();
	int now=res=flow();
	for(int i=1;i<=N;++i){
		if(i==C1-N||i==C2)continue;
		del[i]=true;
		makegraph();
		if(flow()==now-1)
			--now;
		else
			del[i]=false;
	}
}
void output(int v){
	static bool first=true;
	if(first){
		printf("%d",v);
		first=false;
	}
	else
		printf(" %d",v);
}
void output(){
	freopen("telecow.out","w",stdout);
	printf("%d\n",res);
	for(int i=1;i<=N;++i)
		if(del[i])output(i);
	putchar('\n');
}

int main(){
	//freopen("telecow.log","w",stdout);
	input();
	solve();
	output();
}
