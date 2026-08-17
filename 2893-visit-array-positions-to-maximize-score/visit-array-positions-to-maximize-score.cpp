class Solution {
public:
    
    long long ans(vector<int>& nums, int x,int i,int parity,vector<vector<long long>>&dp){
        
        if(i==nums.size())return 0;
        int p = parity+1;
        if(dp[i][p]!=-1)return dp[i][p];
        long long skip=ans(nums,x,i+1,parity,dp);
        long long pick ;
        if((nums[i]%2)==(parity )||parity==-1){
            pick = ans(nums,x,i+1,nums[i]%2,dp)+nums[i];
           
        }
        else {
           
            pick = ans(nums,x,i+1,nums[i]%2,dp)+nums[i]-x;
            
        }
        return dp[i][p]=max(skip,pick);
    }
    long long maxScore(vector<int>& nums, int x) {
        vector<vector<long long>>dp(nums.size(),vector<long long>(3,-1));
        return nums[0]+ans(nums,x,1,nums[0]%2,dp);

    }
};