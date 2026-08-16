class Solution {
public:
    int x=0;
    int ways(vector<int>& nums, int target,int i,int sum,vector<vector<int>>& dp){
        
        if(i== nums.size()){
            if(sum==target)return 1;
            else return 0 ;
        }
        if(dp[i][sum+x]!=-1)return dp[i][sum+x];

        int add = ways(nums,target,i+1,sum + nums[i],dp);
        auto subtract = ways(nums,target,i+1,sum - nums[i],dp);
        return dp[i][sum+x]=add +subtract;
    } 
    int findTargetSumWays(vector<int>& nums, int target) {
        for (int i : nums) x+=i;
        vector<vector<int>> dp (nums.size(),vector<int>(2*x+1,-1));     
        return ways(nums,target,0,0,dp);

      
        
    }

    
};