// Find an index of an array such that its value occurs at more than half of indices in the array.

#include<stack>
int solution(vector<int> &a){
    int n = a.size();
    if(n==0) return -1;
    std::stack<int> leader;
    leader.push(a[0]);
    for(auto i = 1; i < n; ++i){
        leader.push(a[i]);
        if(leader.size()>1){
            int top = leader.top();
            leader.pop();
            if(leader.top() != top)
                leader.pop();
            else
                leader.push(top);
        }
    }
    if(leader.size()==0) return -1;
    int candidate = leader.top();
    int count = 0;
    int index = 0;
    for(auto i = 0; i < n; ++i){
        if(a[i]==candidate){
            count++;
            index = i;
        }
    }
    if(count > n/2) return index;
    else return -1;
}