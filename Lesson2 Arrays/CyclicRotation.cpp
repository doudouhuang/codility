// Rotate an array to the right by a given number of steps

vector<int> solution(vector<int> &A, int K) {
    int N = A.size();
    if(N == 0) return A;
    K = K % N;
    vector<int> temp = A;
    for(int i = 0; i < N; ++i){
        if(i <= N-K-1){
            A[i+K] = temp[i];
        }
        else
        {
            A[i-N+K] = temp[i];
        }
    }
    return A;
}