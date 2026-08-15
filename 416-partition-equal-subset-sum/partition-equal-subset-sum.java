class Solution {
    public boolean canPartition(int[] nums) {

        int sum = 0 ;
        for (int i : nums) sum+=i;
        if (sum%2!=0)return false;
        int target = sum/2;
        int [][]dp = new int[nums.length][target +1];
        for(int row[]:dp)Arrays.fill(row,-1);
        return subset(0, nums, dp,target);
    }

    private boolean subset(int i , int [] nums,int[][] dp,int target){
        boolean ans = false;
        if(i==nums.length)return(target==0);
        if(dp[i][target]!=-1)return (dp[i][target]==1);

        boolean skip = subset(i+1,nums,dp,target);
        if(target-nums[i]<0)ans = skip;
        else {
            boolean pick = subset(i+1,nums,dp,target-nums[i]);
            ans=pick||skip;
        }
        if(ans)dp[i][target]=1;
        else dp[i][target]=0;
        return ans;
    }
}