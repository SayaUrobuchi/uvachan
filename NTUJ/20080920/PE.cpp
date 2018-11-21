#include<stdio.h>

int digits(int in) {
	
	int out = 1 ;
	
	while(in>=10) {
		out++ ;
		in /= 10 ;
	}
	
	return out ;	
}

int main(void) {

	int arr[110], n, i, x, ans1, ans2, mul, ti = 1 ;
	
	while(scanf("%d",&n)) {
		if(n==0) {
			break ;
		}
		
		n++ ;
		
		for(i=0;i<n;i++) {
			scanf("%d",&arr[i]) ;
		}
		
		scanf("%d",&x) ;
		
		ans1 = 1 ;
		for(i=1;i<n-1;i++) {
			if(arr[i]==0) {
				ans1 += 2 ;
			} else {
				ans1 += 1+digits(arr[i]) ;
				ans1 += 2 ;
			}
		}

		if(arr[n-1]!=0) {
			ans1 += 1+digits(arr[n-1]) ;
		}
		
		ans2 = 0 ;
		mul = 1 ;
		
		for(i=n-1;i>=0;i--) {
			ans2 += mul*arr[i] ;
			mul *= x ;
		}
		
		printf("Polynomial %d: %d %d\n",ti++,ans2,ans1+1) ;
	}
	
	return 0 ;
}
