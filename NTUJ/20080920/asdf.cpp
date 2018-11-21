#include<stdio.h>
#include<stdlib.h>

long node[1000010], head = 1 ;
long ans[1000010] ;
long rans[1000010] ;

bool dd(long a, long b) {
	
	while((a%=b)&&(b%=a));
	return a+b == 1;		
	
}

long find(long n) {
	
	long tar = head, pre = -1 ;
	
	while(dd(tar,n)==true) {
		pre = tar ;
		tar = node[tar] ;
	}
	
	if(pre==-1) {
		head = node[tar] ;
	} else {
		node[pre] = node[tar] ;
	}
	
	return tar ;	
}

void gen(void) {
	
	long i ;
	
	ans[1] = 1 ;
	ans[2] = 2 ;
	
	for(i=3;i<100000;i++) {
		ans[i] = find(ans[i-1]) ;
	}
	
	for(i=1;i<1000010;i++) {
		rans[ans[i]] = i-1 ;
	}
}

int main()
{
	long i ;
	
	for(i=1;i<=1000000;i++) {
		node[i] = i+1 ;
	}
	
	gen() ;
	
	while(scanf("%ld",&i)) {
		if(i==0) {
			break ;
		}
		
		printf("The number %ld appears in location %ld.\n",i,rans[i]) ;
	}	
	return 0;
}
