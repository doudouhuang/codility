// Determine whether a triangle can be built from a given set of edges.
// Notice that (long int)(INT_MAX + INT_MAX) = 2; (long int)INT_MAX + (long int)INT_MAX = 4,294,967,294

#include <algorithm>

int solution(vector<int> &A) {
    int n = A.size();
    if(n<3) return 0;
    sort(A.begin(), A.end());
    for(int i = 0; i < n-2; ++i){
        if((long int)A[i] + (long int)A[i+1] > A[i+2]) return 1;
    }
    return 0;
}