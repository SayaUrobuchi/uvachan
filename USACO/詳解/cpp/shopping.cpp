/*
ID: dd.ener1
PROG: shopping
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

struct offer{
	long n;
	long c[5],k[5];
	long p;
}ofs[110];

long S,B;
long need[5];
long mapx[1000];
long mapy[5];
long price[5];//商品原价

unsigned long dis[6][6][6][6][6];
bool inque[6][6][6][6][6];
long V;

void input(){
	freopen("shopping.in","r",stdin);
	scanf("%d",&S);
	memset(ofs,0,sizeof(ofs));
	for(long i=0;i<S;++i){
		scanf("%d",&ofs[i].n);
		for(long j=0;j<ofs[i].n;++j)
			scanf("%d%d",&ofs[i].c[j],&ofs[i].k[j]);
		scanf("%d",&ofs[i].p);
	}
	scanf("%d",&B);
	memset(mapx,-1,sizeof(mapx));
	for(long i=0;i<B;++i){
		long c,k,p;
		scanf("%d%d%d",&c,&k,&p);
		mapx[c]=i;
		need[i]=k;
		mapy[i]=c;
		price[i]=p;
	}
}
long resv[5];
unsigned long newprice;
bool edge(const long nowv[5],const offer& o){
	for(long i=0;i<5;++i)
		resv[i]=nowv[i];
	for(long i=0;i<o.n;++i){
		long nowx=mapx[o.c[i]];
		if(nowx==-1)return false;
		resv[nowx]+=o.k[i];
		if(resv[nowx]>need[nowx])return false;
	}
	newprice=dis[nowv[0]][nowv[1]][nowv[2]][nowv[3]][nowv[4]]+o.p;
	return true;
}
bool edge(const long nowv[5],long k){
	if(nowv[k]+1>need[k])return false;
	for(long i=0;i<5;++i)
		resv[i]=nowv[i];
	++resv[k];
	newprice=dis[nowv[0]][nowv[1]][nowv[2]][nowv[3]][nowv[4]]+price[k];
	return true;
}
bool update(const long s[5],unsigned long updater){
	unsigned long &now=dis[s[0]][s[1]][s[2]][s[3]][s[4]];
	if(now<=updater)return false;
	now=updater;
	return true;
}
struct vertex{
	vertex(){}
	vertex(long a,long b,long c,long d,long e){
		s[0]=a;s[1]=b;s[2]=c;s[3]=d;s[4]=e;
	}
	long s[5];
	void output(){
		printf("dis[%d][%d][%d][%d][%d]=%d\n",s[0],s[1],s[2],s[3],s[4],dis[s[0]][s[1]][s[2]][s[3]][s[4]]);
	}
};
void SPFA(){
	queue<vertex> que(10000);
	memset(inque,0,sizeof(inque));
	memset(dis,-1,sizeof(dis));
	dis[0][0][0][0][0]=0;
	que.push(vertex(0,0,0,0,0));
	inque[0][0][0][0][0]=true;
	do{
		vertex v=que.pop();
		inque[v.s[0]][v.s[1]][v.s[2]][v.s[3]][v.s[4]]=false;
		for(long j=0;j<B;++j){
			if(!edge(v.s,j))continue;
			if(!update(resv,newprice))continue;
			if(inque[resv[0]][resv[1]][resv[2]][resv[3]][resv[4]])continue;
			inque[resv[0]][resv[1]][resv[2]][resv[3]][resv[4]]=true;
			que.push(vertex(resv[0],resv[1],resv[2],resv[3],resv[4]));
		}
		for(long j=0;j<S;++j){
			if(!edge(v.s,ofs[j]))continue;
			if(!update(resv,newprice))continue;
			if(inque[resv[0]][resv[1]][resv[2]][resv[3]][resv[4]])continue;
			inque[resv[0]][resv[1]][resv[2]][resv[3]][resv[4]]=true;
			que.push(vertex(resv[0],resv[1],resv[2],resv[3],resv[4]));
		}
	}while(!que.empty());
}
void output(){
	freopen("shopping.out","w",stdout);
	printf("%d\n",dis[need[0]][need[1]][need[2]][need[3]][need[4]]);
}
int main(){
	//freopen("shopping.log","w",stdout);
	input();
	SPFA();
	output();
	return 0;
}
