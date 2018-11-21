/*
ID: dd.ener1
PROG: packrec
LANG: C++
*/
#include <fstream>

bool cans[210][210];
long rec[4][2];
long best;

inline const long& max2(const long& a,const long& b){
	return a>b?a:b;
}
inline const long& max3(const long& a,const long& b,const long& c){
	return max2(max2(a,b),c);
}
inline const long& max4(const long& a,const long& b,const long& c,const long& d){
	return max3(max2(a,b),c,d);
}
void input(){
	best=100000000;
	std::memset(cans,0,sizeof(cans));
	std::ifstream cin("packrec.in");
	for(long i=0;i<4;++i){
		cin>>rec[i][0]>>rec[i][1];
	}
}
inline void update(long x,long y){
	if(x*y<best)best=x*y;
	cans[x][y]=cans[y][x]=true;
}
inline void assign1(long ax,long ay,long bx,long by,long cx,long cy,long dx,long dy){
	update(max4(ax,bx,cx,dx),ay+by+cy+dy);
}
inline void assign2(long ax,long ay,long bx,long by,long cx,long cy,long dx,long dy){
	update(max3(ax,bx,cx)+dx,max2(ay+by+cy,dy));
}
inline void assign3(long ax,long ay,long bx,long by,long cx,long cy,long dx,long dy){
	update(max2(ax+bx,cx)+dx,max2(max2(ay,by)+cy,dy));
}
inline void assign4(long ax,long ay,long bx,long by,long cx,long cy,long dx,long dy){
	update(max3(ax,bx+cx,dx),ay+max2(by,cy)+dy);
}
inline void assign5(long ax,long ay,long bx,long by,long cx,long cy,long dx,long dy){
	if(ax>bx||cx<dx||by>dy)return;
	update(max2(ax+cx,bx+dx),max2(ay+by,cy+dy));
}
inline void assign(long ax,long ay,long bx,long by,long cx,long cy,long dx,long dy){
	assign1(ax,ay,bx,by,cx,cy,dx,dy);
	assign2(ax,ay,bx,by,cx,cy,dx,dy);
	assign3(ax,ay,bx,by,cx,cy,dx,dy);
	assign4(ax,ay,bx,by,cx,cy,dx,dy);
	assign5(ax,ay,bx,by,cx,cy,dx,dy);
}
inline void search(long a,long b,long c,long d){
	assign(rec[a][0],rec[a][1],rec[b][0],rec[b][1],rec[c][0],rec[c][1],rec[d][0],rec[d][1]);
	assign(rec[a][1],rec[a][0],rec[b][0],rec[b][1],rec[c][0],rec[c][1],rec[d][0],rec[d][1]);
	assign(rec[a][0],rec[a][1],rec[b][1],rec[b][0],rec[c][1],rec[c][0],rec[d][0],rec[d][1]);
	assign(rec[a][0],rec[a][1],rec[b][0],rec[b][1],rec[c][1],rec[c][0],rec[d][0],rec[d][1]);
	assign(rec[a][0],rec[a][1],rec[b][0],rec[b][1],rec[c][0],rec[c][1],rec[d][1],rec[d][0]);
	assign(rec[a][1],rec[a][0],rec[b][1],rec[b][0],rec[c][0],rec[c][1],rec[d][0],rec[d][1]);
	assign(rec[a][0],rec[a][1],rec[b][1],rec[b][0],rec[c][1],rec[c][0],rec[d][0],rec[d][1]);
	assign(rec[a][0],rec[a][1],rec[b][0],rec[b][1],rec[c][1],rec[c][0],rec[d][1],rec[d][0]);
	assign(rec[a][1],rec[a][0],rec[b][0],rec[b][1],rec[c][0],rec[c][1],rec[d][1],rec[d][0]);
	assign(rec[a][1],rec[a][0],rec[b][0],rec[b][1],rec[c][1],rec[c][0],rec[d][0],rec[d][1]);
	assign(rec[a][1],rec[a][0],rec[b][0],rec[b][1],rec[c][0],rec[c][1],rec[d][1],rec[d][0]);
	assign(rec[a][1],rec[a][0],rec[b][1],rec[b][0],rec[c][1],rec[c][0],rec[d][1],rec[d][0]);
	assign(rec[a][0],rec[a][1],rec[b][1],rec[b][0],rec[c][1],rec[c][0],rec[d][1],rec[d][0]);
	assign(rec[a][1],rec[a][0],rec[b][0],rec[b][1],rec[c][1],rec[c][0],rec[d][1],rec[d][0]);
	assign(rec[a][1],rec[a][0],rec[b][1],rec[b][0],rec[c][0],rec[c][1],rec[d][1],rec[d][0]);
	assign(rec[a][1],rec[a][0],rec[b][1],rec[b][0],rec[c][1],rec[c][0],rec[d][0],rec[d][1]);
}
inline void search(){
	search(0,1,2,3);
	search(0,1,3,2);
	search(0,2,1,3);
	search(0,2,3,1);
	search(0,3,1,2);
	search(0,3,2,1);
	search(1,0,2,3);
	search(1,0,3,2);
	search(1,2,0,3);
	search(1,2,3,0);
	search(1,3,0,2);
	search(1,3,2,0);
	search(2,0,1,3);
	search(2,0,3,1);
	search(2,1,0,3);
	search(2,1,3,0);
	search(2,3,0,1);
	search(2,3,1,0);
	search(3,0,1,2);
	search(3,0,2,1);
	search(3,1,0,2);
	search(3,1,2,0);
	search(3,2,0,1);
	search(3,2,1,0);
}
void output(){
	std::ofstream cout("packrec.out");
	cout<<best<<std::endl;
	for(long a=1;;++a){
		if(best%a)continue;
		long b=best/a;
		if(a>b)break;
		if(cans[a][b])cout<<a<<' '<<b<<std::endl;
	}
}
int main(){
	input();
	search();
	output();
	return 0;
}
