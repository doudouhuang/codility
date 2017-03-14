// Find the index S such that the leaders of the sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] are the same

int solution(vector<int> &A){
    int n = A.size();
    int candidate = 0;
    int count = 0;
    for(int i = 0; i < n; ++i){
        if(count == 0){
            candidate = A[i];
            count++;
        }
        else{
            if(A[i] == candidate)
                count++;
            else
                count--;
        }
    }
    int countCandi = 0;
    for(int i = 0; i < n; ++i){
        if(A[i] == candidate)
            countCandi++;
    }
    if(countCandi <= n/2)
        return 0;
    
    int countEqui = 0;
    int leadLeft = 0;
    for(int i = 0; i < n; ++i){
        if(A[i] == candidate)
            leadLeft++;
        int leadRight = countCandi - leadLeft;
        if(leadLeft > (i+1)/2 && leadRight > (n-i-1)/2)
            countEqui++;
    }
    return countEqui++;
}
