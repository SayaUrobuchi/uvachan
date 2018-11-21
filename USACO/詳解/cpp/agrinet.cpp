/*
ID: dd.ener1
PROG: agrinet
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

template <class T>
class Heap{
	private:
		long size;
		T* s;
	public:
		Heap(long n,T MinValue):s(new T[n+1]),size(0){
			s[0]=MinValue;
		}
		void Push(const T& item){
			long i;
			for(i=++size;item<s[i/2];i/=2)
				s[i]=s[i/2];
			s[i]=item;
		}
		T Pop(){
			T min=s[1];
			T last=s[size--];
			long i,child;
			for(i=1;i*2<=size;i=child){
				child=i*2;
				if(child!=size&&s[child+1]<s[child])++child;
				if(s[child]<last)s[i]=s[child];
				else break;
			}
			s[i]=last;
			return min;
		}
};
class UFSet{
	private:
		long n;
		long* p;
	public:
		UFSet(long size):n(size),p(new long[n]){
			memset(p,-1,sizeof(long)*n);
		}
		long Find(long k){
			if(p[k]==-1)return k;
			return p[k]=Find(p[k]);
		}
		bool Union(long i,long j){
			long pi=Find(i);
			long pj=Find(j);
			if(pi==pj)return false;
			p[pi]=pj;
			return true;
		}
};
struct Edge{
	Edge(){}
	Edge(long _w,long _v1,long _v2):w(_w),v1(_v1),v2(_v2){}
	long w;
	long v1,v2;
	bool operator<(const Edge& rhs)const{
		return w<rhs.w;
	}
};
long N;
long g[110][110];
void input(){
	freopen("agrinet.in","r",stdin);
	scanf("%d",&N);
	for(long i=0;i<N;++i)
		for(long j=0;j<N;++j)
			scanf("%d",&g[i][j]);
}
long solve(){
	long res=0;
	Heap<Edge> heap(N*N,Edge(-100000000,-1,-1));
	UFSet set(N);
	for(long i=0;i<N;++i)
		for(long j=i+1;j<N;++j)
			heap.Push(Edge(g[i][j],i,j));
	for(long i=1;i<N;){
		Edge now=heap.Pop();
		if(!set.Union(now.v1,now.v2))continue;
		res+=now.w;
		++i;
	}
	return res;
}
void output(long res){
	freopen("agrinet.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	//freopen("agrinet.log","w",stdout);
	input();
	output(solve());
	return 0;
}
