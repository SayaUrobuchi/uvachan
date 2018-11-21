/*
ID: dd.ener1
PROG: milk6
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
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

const int maxn=36,maxe=1200;
int G[maxn][maxn];
int pre[maxn];
bool vis[maxn];
struct edge{
	int a,b,f;
	int n;
}E[maxe];
int N,M;
bool del[maxe];//±»É¾µôµÄ±ß 
int res;

void input(){
	freopen("milk6.in","r",stdin);
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;++i){
		scanf("%d%d%d",&E[i].a,&E[i].b,&E[i].f);
		E[i].n=i+1;
	}
}
void buildgraph(){
	memset(G,0,sizeof(G));
	for(int i=0;i<M;++i){
		if(del[i])continue;
		G[E[i].a][E[i].b]+=E[i].f;
	}
}
void findway(){
	memset(pre,-1,sizeof(pre));
	memset(vis,0,sizeof(vis));
	queue<int> que(N+10);
	que.push(1);
	vis[1]=true;
	while(!que.empty()){
		int now=que.pop();
		for(int i=1;i<=N;++i){
			if(G[now][i]&&!vis[i]){
				vis[i]=true;
				pre[i]=now;
				que.push(i);
			}
		}
	}
}
int solveway(){
	int least=1000000000;
	for(int now=N;now!=1;now=pre[now])
		if(G[pre[now]][now]<least)least=G[pre[now]][now];
	for(int now=N;now!=1;now=pre[now]){
		G[pre[now]][now]-=least;
		G[now][pre[now]]+=least;
	}
	return least;
}
int flow(){
	int res=0;
	for(;;){
		findway();
		if(!vis[N])break;
		res+=solveway();
	}
	return res;
}
int compare(const void* a,const void* b){
	edge *x=(edge*)a,*y=(edge*)b;
	if(x->f>y->f)return -1;
	if(y->f>x->f)return 1;
	return x->n-y->n;
}
void solve(){
	qsort(E,M,sizeof(edge),compare);
	memset(del,0,sizeof(del));
	buildgraph();
	res=flow();
	int pre=res;
	for(int k=0;k<M;++k){
		del[k]=true;
		buildgraph();
		int now=flow();
		if(pre-now==E[k].f)
			pre=now;
		else
			del[k]=false;
	}
}
void output(){
	freopen("milk6.out","w",stdout);
	int res2=0;
	bool e[maxe];
	memset(e,0,sizeof(e));
	for(int i=0;i<M;++i)
		if(del[i]){
			e[E[i].n]=true;
			++res2;
		}
	printf("%d %d\n",res,res2);
	for(int i=1;i<=M;++i){
		if(!e[i])continue;
		printf("%d\n",i);
	}
}
int main(){
	//freopen("milk6.log","w",stdout);
	input();
	solve();
	output();
}
