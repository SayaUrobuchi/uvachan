/*
ID: dd.ener1
PROG: butter
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
};

long N,P;
long b[810][1500];//第二个顶点 
unsigned long w[810][1500];//权 
long s[810];//边数 
long cow[600];
unsigned long dis[810];
bool inque[810];

void input(){
	freopen("butter.in","r",stdin);
	long m;
	scanf("%d%d%d",&N,&P,&m);
	for(long i=0;i<N;++i){
		scanf("%d",cow+i);
		--cow[i];
	}
	do{
		long v1,v2,ww;
		scanf("%d%d%d",&v1,&v2,&ww);
		--v1;--v2;
		b[v1][s[v1]]=v2;
		w[v1][s[v1]]=ww;
		++s[v1];
		b[v2][s[v2]]=v1;
		w[v2][s[v2]]=ww;
		++s[v2];
	}while(--m);
}
template <class T>
inline bool update(T& old,const T& updater){
	if(updater<old){
		old=updater;
		return true;
	}
	return false;
}
void SPFA(long source){
	static queue<long> que(P+1);
	memset(dis,-1,sizeof(dis));
	memset(inque,0,sizeof(inque));
	dis[source]=0;
	que.init();
	que.push(source);
	inque[source]=true;
	do{
		long i=que.pop();
		inque[i]=false;
		for(long j=0;j<s[i];++j){
			long next=b[i][j];
			if(update(dis[next],dis[i]+w[i][j])&&!inque[next]){
				que.push(next);
				inque[next]=true;
			}
		}
	}while(!que.empty());
}
unsigned long solvenow(){
	unsigned long res=0;
	for(long i=0;i<N;++i)
		res+=dis[cow[i]];
	return res;
}
long solve(){
	unsigned long best=~0;
	for(long i=0;i<P;++i){
		SPFA(i);
		long now=solvenow();
		if(now<best)best=now;
	}
	return best;
}
void output(long res){
	freopen("butter.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	input();
	output(solve());
}
