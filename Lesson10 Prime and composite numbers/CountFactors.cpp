#include<cmath>
int solution(int N){
	if(N==1) return 1;
	if(N==2) return 2;
    
    double sq = sqrt(N);
    int countFactor = 2;
    int i = 2;
    while(i < sq){
    	if(N % i == 0) countFactor += 2;
    	i++;
    }
    if(i == (int)sq) countFactor++;
    return countFactor;
}