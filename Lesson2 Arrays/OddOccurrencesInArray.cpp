// An array contains odd number of elements, each element can be paired with another one except one

int solution(vector<int> &A) {
    int ans = 0;
    for(int i = 0; i < A.size(); ++i){
        ans ^= A[i];
    }
    return ans;
}