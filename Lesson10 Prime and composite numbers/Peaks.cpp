// Divide an array into the maximum number of same-sized blocks, each of which should contain an index P such that A[P - 1] < A[P] > A[P + 1]

int solution(vector<int> &A) {
    int n = A.size();
    if(n<3) return 0;
    vector<int> peak;
    for (int i = 1; i < n-1; ++i) {
        if(A[i] > A[i-1] && A[i] > A[i+1]){
            peak.push_back(i);
        }
    }
    int m = peak.size();
    if(m == 0) return 0;
    
    int maxMiddleZero = 0;
    for(int i = 1; i < m; ++i){
        maxMiddleZero = peak[i] - peak[i-1] - 1 > maxMiddleZero ? peak[i] - peak[i-1] - 1 : maxMiddleZero;
    }
    
    int beginZero = peak[0];
    int endZero = n - 1 - peak[m-1];
    // minimal numbers per block
    int numberPerBlock = max((maxMiddleZero+1)/2+1, max(beginZero+1,endZero+1));
    for (int k = numberPerBlock; k <= n; ++k) {
        // if divisible, check if every block has a peak
        if(n % k == 0) {
            int lower = 0;
            int upper = k-1;
            for(int j = 0; j < m; ++j){
                if(peak[j] >= lower && peak[j] <= upper){
                    lower += k;
                    upper += k;
                }
            }
            if(upper == n-1+k)
                return n / k;
        }
    }
    return 0;
}