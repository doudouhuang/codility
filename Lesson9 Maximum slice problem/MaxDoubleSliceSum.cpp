// Find the maximal sum of any double slice.
int solution(vector<int> &a) {
    // a[0], a[n-1] not useful
    a.erase(a.begin());
    a.erase(a.end()-1);
    int n = a.size();
    if(n==1) return 0;
    
    int leftSum[n];
    int rightSum[n];
    int ans = 0;
    
    // from left to right: record current max sum
    leftSum[0] = a[0];
    if(leftSum[0] > ans) ans = leftSum[0];
    int i = 1;
    while(i < n-1){
        leftSum[i] = max(a[i], a[i]+leftSum[i-1]);
        if(leftSum[i] > ans) ans = leftSum[i];
        i++;
    }
    
    // from right to left: record current max sum
    rightSum[n-1] = a[n-1];
    if(rightSum[n-1] > ans) ans = rightSum[n-1];
    int j = n-2;
    while(j > 0){
        rightSum[j] = max(a[j], a[j]+rightSum[j+1]);
        if(rightSum[j] > ans) ans = rightSum[j];
        j--;
    }
    
    
    int k = 0;
    while(k < n-2){
        int temp = leftSum[k]+rightSum[k+2];
        if(temp > ans)
            ans = temp;
        k++;
    }
    
    return ans;
}