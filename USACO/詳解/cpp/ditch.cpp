/*
ID: dd.ener1
PROG: ditch
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

const long maxn=210;

long N;
long u[maxn][maxn];//»¡ 
long pre[maxn];
bool vis[maxn];
long res;

void input(){
	memset(u,0,sizeof(u));
	freopen("ditch.in","r",stdin);
	long m;
	scanf("%d%d",&m,&N);
	while(m--){
		long a,b,s;
		scanf("%d%d%d",&a,&b,&s);
		if(a==N)continue;
		u[a-1][b-1]+=s;
	};
	--N;
}
void findway(){
	memset(pre,-1,sizeof(pre));
	memset(vis,0,sizeof(vis));
	queue<long> que(N+10);
	que.push(0);
	vis[0]=true;
	while(!que.empty()){
		long now=que.pop();
		for(long i=0;i<=N;++i){
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
	for(;;){
		findway();
		if(!vis[N])break;
		solveway();
	}
	for(long i=0;i<N;++i)
		res+=u[N][i];
}
void output(){
	freopen("ditch.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	//freopen("ditch.log","w",stdout);
	input();
	solve();
	output();
}
