#include<stdio.h>

double s1, s2, t ;
bool isans ;
double pos[8][2] ;

double area3(int a, int b, int c) {
	
	double out = 0 ;
	
	out = pos[a][0]*pos[b][1]+pos[b][0]*pos[c][1]+pos[c][0]*pos[a][1]-pos[a][1]*pos[b][0]-pos[b][1]*pos[c][0]-pos[c][1]*pos[a][0] ;
	if(out<0) {
		out = 0-out ;
	}
	
	return out/2 ;	
}

double area4(int a, int b, int c, int d) {
	
	double out = 0 ;
	
	out = pos[a][0]*pos[b][1]+pos[b][0]*pos[c][1]+pos[c][0]*pos[d][1]+pos[d][0]*pos[a][1]-pos[a][1]*pos[b][0]-pos[b][1]*pos[c][0]-pos[c][1]*pos[d][0]-pos[d][1]*pos[a][0] ;
	if(out<0) {
		out = 0-out ;
	}
	
	return out/2 ;	
}

void ifans(double a) {
	
	double b = t-a, tmp ;
	
	if(a>b) {
		tmp = a ;
		a = b ;
		b = tmp ;
	}
	
	if(isans==false||b-a<s2-s1) {
		isans = true ;
		s1 = a ;
		s2 = b ;
	}
	
}

int main(void) {
	
	int i, ti = 1 ;
	
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&pos[0][0],&pos[0][1],&pos[2][0],&pos[2][1],&pos[4][0],&pos[4][1],&pos[6][0],&pos[6][1])) {
		
		if(pos[0][0]==0&&pos[0][1]==0&&pos[2][0]==0&&pos[2][1]==0&&pos[4][0]==0&&pos[4][1]==0&&pos[6][0]==0&&pos[6][1]==0) {
			break ;
		}
		
		pos[1][0] = (pos[0][0]+pos[2][0]) / 2 ; 
		pos[1][1] = (pos[0][1]+pos[2][1]) / 2 ; 
		pos[3][0] = (pos[2][0]+pos[4][0]) / 2 ; 
		pos[3][1] = (pos[2][1]+pos[4][1]) / 2 ; 
		pos[5][0] = (pos[4][0]+pos[6][0]) / 2 ; 
		pos[5][1] = (pos[4][1]+pos[6][1]) / 2 ; 
		pos[7][0] = (pos[6][0]+pos[0][0]) / 2 ; 
		pos[7][1] = (pos[6][1]+pos[0][1]) / 2 ;
		
		t = area4(0,2,4,6) ;
		
		isans = false ;
		
		ifans(area3(0,2,3)) ;
		ifans(area3(0,2,4)) ;
		ifans(area3(0,5,6)) ;
		ifans(area3(1,2,3)) ;
		ifans(area3(1,2,4)) ;
		ifans(area4(1,2,4,5)) ;
		ifans(area3(1,0,6)) ;
		ifans(area3(1,0,7)) ;
		ifans(area3(2,4,5)) ;
		ifans(area3(2,4,6)) ;
		ifans(area3(2,0,7)) ;
		ifans(area3(3,4,5)) ;
		ifans(area3(3,4,6)) ;
		ifans(area4(3,4,6,7)) ;
		ifans(area3(4,6,7)) ;
		ifans(area3(5,6,7)) ;
		
		printf("Cake %d: %.3lf %.3lf\n",ti++,s1,s2) ;
	}
	
	return 0 ;
} 
