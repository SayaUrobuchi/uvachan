/*
ID: dd.ener1
PROG: maze1
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

template <class T>
class queue{
	public:
		queue(long maxn):s(new T[maxn]),head(0),tail(0){}
		void enque(const T& i){
			s[tail++]=i;
		}
		const T& deque(){
			return s[head++];
		}
		void init(){
			head=tail=0;
		}
		bool empty(){
			return head==tail;
		}
	private:
		T* s;
		long head,tail;
};
struct DFSitem{
	DFSitem(){}
	DFSitem(long nowX,long nowY,long nowN):x(nowX),y(nowY),n(nowN){}
	long x,y,n;
};
long W,H;
long outx[2],outy[2];
char map[259][100];
bool vis[250][100];
long dis[250][100];
void input(){
	freopen("maze1.in","r",stdin);
	scanf("%d %d\n",&W,&H);
	W=W*2+1;
	H=H*2+1;
	for(long i=0;i<H;++i)
		for(long j=0;;++j){
			char c=getchar();
			if(c=='\n')break;
			map[i][j]=c;
		}	
}
inline void addout(long x,long y){
	static long k=0;
	outx[k]=x;
	outy[k]=y;
	++k;
}
void solveout(){
	for(long x=0;x<H;++x){
		if(map[x][0]==' ')
			addout(x,0);
		if(map[x][W-1]==' ')
			addout(x,W-1);
	}
	for(long y=1;y<W-1;++y){
		if(map[0][y]==' ')
			addout(0,y);
		if(map[H-1][y]==' ')
			addout(H-1,y);
	}
}
inline bool cango(long x,long y){
	return map[x][y]==' ';
}
long solve(){
	static queue<DFSitem> q((H+1)*(W+1));
	q.init();
	memset(vis,0,sizeof(vis));
	q.enque(DFSitem(outx[0],outy[0],0));
	vis[outx[0]][outy[0]]=true;
	q.enque(DFSitem(outx[1],outy[1],0));
	vis[outx[1]][outy[1]]=true;
	for(;;){
		if(q.empty())break;
		const DFSitem &t=q.deque();
		dis[t.x][t.y]=t.n;
		if(t.x!=H-1&&!vis[t.x+1][t.y]&&cango(t.x+1,t.y)){
			q.enque(DFSitem(t.x+1,t.y,t.n+1));
			vis[t.x+1][t.y]=true;
		}
		if(t.x!=0&&!vis[t.x-1][t.y]&&cango(t.x-1,t.y)){
			q.enque(DFSitem(t.x-1,t.y,t.n+1));
			vis[t.x-1][t.y]=true;
		}
		if(t.y!=W-1&&!vis[t.x][t.y+1]&&cango(t.x,t.y+1)){
			q.enque(DFSitem(t.x,t.y+1,t.n+1));
			vis[t.x][t.y+1]=true;
		}
		if(t.y!=0&&!vis[t.x][t.y-1]&&cango(t.x,t.y-1)){
			q.enque(DFSitem(t.x,t.y-1,t.n+1));
			vis[t.x][t.y-1]=true;
		}
	}
	long res=-1;
	for(long x=0;x<H;++x)
		for(long y=0;y<W;++y){
			if(!(x%2)||!(y%2))continue;
			if(!cango(x,y))continue;
			long now=dis[x][y];
			if(now>res)res=now;
		}
	return res;
}
inline long min(long a,long b){
	return a<b?a:b;
}
long output(long res){
	freopen("maze1.out","w",stdout);
	printf("%d\n",(res+1)/2);
}
int main(){
	input();
	solveout();
	output(solve());
}
