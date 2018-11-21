/*
ID: dd.ener1
PROG: frac1
LANG: C++
*/
#include <cstdio>
using namespace std;

template<class T>
inline void swap(T& l,T& r){
    T tmp=r;
    r=l;
    l=tmp;
}
template<class T>
void qsort(T s1[],long low,long hi){
    if(low>=hi)return;
    T x=s1[(low+hi)/2];
    swap(s1[low],s1[(low+hi)/2]);
    long l=low,r=hi;
    while(l<r){
        while(l<r&&s1[r]>=x)--r;
        s1[l]=s1[r];
        while(l<r&&s1[l]<=x)++l;
        s1[r]=s1[l];
    }
    s1[l]=x;
    qsort(s1,low,l-1);
    qsort(s1,r+1,hi);
}
struct frac{
	long a,b;
	frac():a(0),b(0){}
	frac(long aa,long bb):a(aa),b(bb){}
	bool operator<=(const frac& rhs)const{
		return a*rhs.b<=b*rhs.a;
	}
	bool operator>=(const frac& rhs)const{
		return a*rhs.b>=b*rhs.a;
	}
};
frac* fracs;
long n;
long N;
void input(){
	freopen("frac1.in","r",stdin);
	scanf("%d",&N);
	fracs=new frac[N*N];
}
long gcd(long a,long b){
	if(b==0)return a;
	return gcd(b,a%b);
}
void produce(){
	for(long i=1;i<=N;++i)
		for(long j=1;j<i;++j)
			if(gcd(j,i)==1)
				fracs[n++]=frac(j,i);
	fracs[n++]=frac(0,1);
	fracs[n++]=frac(1,1);
}
void output(){
	freopen("frac1.out","w",stdout);
	for(long i=0;i<n;++i)
		printf("%d/%d\n",fracs[i].a,fracs[i].b);
}
int main(){
	input();
	produce();
	qsort(fracs,0,n-1);
	output();
}
