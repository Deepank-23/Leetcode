class Solution {
public:
    int fibo(int n,vector<int> &ddd){
        if(ddd[n]!=-1)return ddd[n];
        if(n<=1) return n;
        return ddd[n] = fibo(n-1,ddd) +fibo(n-2,ddd);
    }
    
    int fib(int n) {
        vector<int> ddd(n+1,-1);
        return fibo(n,ddd);
    }
};