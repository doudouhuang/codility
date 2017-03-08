// FrogRiverOne
// The goal is to find the earliest time that 1,...,X all appear in array A


int solution(int X, vector<int> &A) {
    int n = A.size();
    vector<int> track(X,1);
    for(int i = 0; i < n; ++i){
        if(track[A[i]-1] == 1){
            track[A[i]-1] = 0;
            X--;
        }
        if(X==0){
            return i;
        }
    }
    return -1;
}