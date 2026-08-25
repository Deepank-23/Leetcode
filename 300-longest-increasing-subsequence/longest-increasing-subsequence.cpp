class Solution {
public:
    int dps(vector<int>& nums, int i, int last, vector<vector<int>>& dp){

        if(i == -1)
            return 0;

        if(dp[i][last] != 0)
            return dp[i][last];

        int skip = dps(nums, i-1, last, dp);

        int take = 0;

        if(last == nums.size() || nums[i] < nums[last]){
            take = 1 + dps(nums, i-1, i, dp);
        }

        return dp[i][last] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n+1,0));

        return dps(nums,n-1,n,dp);
    }
};