class Solution {
public:
    int perfect(int n){
        int srt = (int) sqrt(n);
        return (srt*srt==n);
    }
    int minn(vector<int> &dp,int n){
        if(perfect(n))return 1;
        if(dp[n]!=0)return dp[n];
        int minm = 34567;
        for(int i=1;i*i<=n;i++){
            int count = minn(dp,i*i)+minn(dp,n-(i*i));
            minm= min(minm,count);
        }
        return dp[n]=minm;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,0);
        return minn(dp,n);
    }
};
