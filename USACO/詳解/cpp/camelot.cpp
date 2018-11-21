/*
ID: dd.ener1
PROG: camelot
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

const long maxP=26*40+20;
const long maxR=26,maxC=40;
long R,C;//R<=40, C<=26
long kingx,kingy;
long knightx[maxP];
long knighty[maxP];
long k_num;
unsigned long g[maxR][maxC][maxR][maxC];
bool inque[maxR][maxC];
long best;

void input(){
	freopen("camelot.in","r",stdin);
	scanf("%d %d\n",&R,&C);
	scanf("%c %d\n",&kingx,&kingy);
	kingx-='A';
	kingy-=1;
	char c;
	long l;
	for(;;){
		for(;;){
			c=getchar();
			if(c!=' '&&c!='\n')break;
		}
		if(feof(stdin))return;
		scanf("%d",&l);
		knightx[k_num]=c-'A';
		knighty[k_num]=l-1;
		++k_num;
	}
}
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
			if(end==N)end=0;
		}
		inline T pop(){
			T res=s[beg];
			++beg;
			if(beg==N)beg=0;
			return res;
		}
		inline bool empty(){
			return beg==end;
		}
};
struct item{
	item(){}
	item(long _x,long _y,long _dis):x(_x),y(_y),dis(_dis){}
	long x,y;
	long dis;
};
void DFS(long x,long y){
	static const long deltax[8]={1,1,-1,-1,2,2,-2,-2};
	static const long deltay[8]={2,-2,2,-2,1,-1,1,-1};
	static queue<item> que(R*C+1);
	que.init();
	memset(inque,0,sizeof(inque));
	for(long i=0;i<C;++i)
		for(long j=0;j<R;++j)
			g[x][y][i][j]=10000;
	g[x][y][x][y]=0;
	inque[x][y]=true;
	que.push(item(x,y,0));
	do{
		item now=que.pop();
		g[x][y][now.x][now.y]=now.dis;
		for(long k=0;k<8;++k){
			long newx=now.x+deltax[k];
			if(newx<0||newx>=C)continue;
			long newy=now.y+deltay[k];
			if(newy<0||newy>=R)continue;
			if(inque[newx][newy])continue;
			que.push(item(newx,newy,now.dis+1));
			inque[newx][newy]=true;
		}
	}while(!que.empty());
}
void DFS(){
	for(long i=0;i<C;++i)
		for(long j=0;j<R;++j)
			DFS(i,j);
}
struct point{
	point(){}
	point(long _x,long _y):x(_x),y(_y){}
	long x,y;
};
long abs(long x){
	return x<0?-x:x;
}
long dis(point carry){
	long x=abs(carry.x-kingx);
	long y=abs(carry.y-kingy);
	return x>y?x:y;
}
void update(long& x,const long y){
	if(x>y)x=y;
}
long solve(const point &gather,const point &carry,long k){
	long res=0;
	res-=g[gather.x][gather.y][knightx[k]][knighty[k]];
	res+=dis(carry);
	res+=g[gather.x][gather.y][carry.x][carry.y];
	res+=g[carry.x][carry.y][knightx[k]][knighty[k]];
	return res;
}
void solve(const point &gather){
	long res=0;
	for(long k=0;k<k_num;++k)
		res+=g[knightx[k]][knighty[k]][gather.x][gather.y];
	if(res>best)return;
	point carry;
	long bestdelta=100000000;
	for(carry.x=0;carry.x<C;++carry.x)
		for(carry.y=0;carry.y<R;++carry.y){
			if(dis(carry)>bestdelta)continue;
			for(long k=0;k<k_num;++k)
				update(bestdelta,solve(gather,carry,k));
		}
	update(best,res+=bestdelta);
}
point midknight(){
	long sumx=0,sumy=0;
	for(long k=0;k<k_num;++k){
		sumx+=knightx[k];
		sumy+=knightx[k];
	}
	return point(sumx/k_num,sumy/k_num);
}
void presolve(){
	point pre=midknight();
	solve(pre);
	pre.x=kingx;
	pre.y=kingy;
	solve(pre);
}
void solve(){
	if(k_num==0){
		best=0;
		return;
	}
	best=1000000000;
	presolve();
	point gather;
	for(gather.x=0;gather.x<C;++gather.x)
		for(gather.y=0;gather.y<R;++gather.y)
			solve(gather);
			
}
void output(){
	freopen("camelot.out","w",stdout);
	printf("%d\n",best);
}
int main(){
	input();
	DFS();
	solve();
	output();
	return 0;
}
