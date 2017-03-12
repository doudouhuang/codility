// Find the minimal perimeter of any rectangle whose area equals N

#include<cmath>
int solution(int N){
    int minPerimeter = 2*(1+N);
    if(N==1 || N==2 || N==3) return minPerimeter;
    
    double sq = sqrt(N);
    int i = 2;
    while(i < sq){
        if(N % i == 0){
            minPerimeter = minPerimeter < 2*(i + N/i)? minPerimeter : 2*(i + N/i);
        }
        i++;
    }
    if(i == (int)sq){
        minPerimeter = minPerimeter < 4*i? minPerimeter : 4*i;
    }
    return minPerimeter;
}