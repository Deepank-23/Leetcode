class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        for(int i=0;i< nums.size();i++){
            if(i==0)dp[0]=nums[0];
            else if(i==1)dp[1]=max(nums[0],nums[1]);
            else dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[nums.size()-1];
    }
};