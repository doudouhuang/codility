// MaxCounters
// Instead of doing max_count every time, keep the last_max if A[i] == N+1

vector<int> solution(int N, vector<int> &A) {
    int last_max = 0;
    int current_max = 0;
    vector<int> ans(N,0);
    for(int i = 0; i < A.size(); ++i){
        if(A[i] != N+1){
            int pos = A[i]-1;
            int current_value = ans[pos];
            if(current_value < last_max){
                ans[pos] = last_max + 1;
            }else{
                ans[pos]++;
            }
            if(ans[pos] > current_max) current_max = ans[pos];
        }else{
            last_max = current_max;
        }
    }
    for(int i = 0; i < N; ++i){
        if(ans[i] < last_max){
            ans[i] = last_max;
        }
    }
    return ans;
}