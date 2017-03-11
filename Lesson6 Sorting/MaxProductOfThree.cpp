/* 
   To maximise A[P] * A[Q] * A[R] for any triplet (P, Q, R)
   A positive number can only be obtained from + + + or - - +
   Sort the array. Check the last three numbers. There are three cases:
   1. A[n-1], A[n-2], A[n-3] all positive
   2. A[n-1], A[n-2], A[n-3] all non-positive i.e. A[n-1] <= 0
   3. otherwise i.e. the array contains one or two positive numbers
*/

#include <algorithm>
int solution(vector<int> &A){
    sort(A.begin(), A.end());
    int n = A.size();
    int a1 = A[n-1];
    int a2 = A[n-2];
    int a3 = A[n-3];
    if(a3>0 && a2>0 && a1>0){
        return a1*a2*a3 > A[0]*A[1]*a1? a1*a2*a3 : A[0]*A[1]*a1;
    }
    if(a1<=0){
        return a1*a2*a3;
    }
    return A[0]*A[1]*a1;
}

// Therefore, the solution can be simplified as:

#include <algorithm>
int solution(vector<int> &A){
    sort(A.begin(), A.end());
    int n = A.size();
	return A[n-1]*A[n-2]*A[n-3] > A[0]*A[1]*A[n-1]? A[n-1]*A[n-2]*A[n-3] : A[0]*A[1]*A[n-1];
}
