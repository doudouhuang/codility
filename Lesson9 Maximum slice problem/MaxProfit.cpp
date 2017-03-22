// Given a log of stock prices compute the maximum possible earning.
// the problem is actually to find max subarray sum of {A[1]-A[0], A[2]-A[1],...,A[n-1]-A[n-2]}

int solution(vector<int> &A) {
    int N = A.size();
    if(N==0) return 0;
    if(N==1) return A[1]>A[0]? A[1]-A[0]:0;
    int currentProfit = 0;
    int globalProfit = 0;
    for(int i = 1; i < N; ++i){
        int temp = A[i]-A[i-1];
        currentProfit = max(temp, temp+currentProfit);
        if(globalProfit < currentProfit)
            globalProfit = currentProfit;
    }
    if(globalProfit <= 0)
        return 0;
    else
        return globalProfit;
}
