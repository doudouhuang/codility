// Find a maximum sum of a compact subsequence of array elements.

int solution(vector<int> &a) {
    int n = a.size();
    if(n==1) return a[0];
    int currentSum = a[0];
    int globalSum = a[0];
    for(int i = 1; i < n; ++i){
        currentSum = max(a[i], a[i]+currentSum);
        if(globalSum < currentSum)
            globalSum = currentSum;
    }
    return globalSum;
}