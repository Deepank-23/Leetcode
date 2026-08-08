class Solution {
public:
    int fib(int n) {
        vector<int> dpit(n+1,0);
        int i = 0;
        while(i<=n){
            if(i<=1)dpit[i]=i;
            else dpit[i]=dpit[i-1]+dpit[i-2];
            i++;
        }
        return dpit[n];
    }
};