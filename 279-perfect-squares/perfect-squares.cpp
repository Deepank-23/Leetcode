class Solution {
public:
    int perfect(int n){
        int srt = (int) sqrt(n);
        return (srt*srt==n);
    }
    
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        
        for(int i= 1;i<=n;i++){
            if(perfect(i))dp[i]=1;
            else{
                int minm = INT_MAX;
                for(int j=1;j*j<=i;j++){
                    int count = dp[j*j]+dp[i-(j*j)];
                    minm= min(minm,count);
                }
                dp[i]=minm;
            }  

        }
        return dp[n];
        
    }
};
