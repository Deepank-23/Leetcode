class Solution {
public:
    int rober(vector<int>&nums,int i,vector<int>& dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int take = nums[i]+rober(nums,i+2,dp);
        int skip = rober(nums,i+1,dp);
        dp[i]=max(take,skip);
        return *max_element(dp.begin(),dp.end());
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,-1);
        return rober(nums,0,dp);
        
    }
};