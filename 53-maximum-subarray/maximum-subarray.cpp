class Solution {

public:
    int total(vector<int>& nums,int i,vector<int>& sum){
        if (i == 0) return nums[0];              
        if (sum[i] != INT_MIN) return sum[i];    
        
        return sum[i] = max(total(nums,i-1,sum)+nums[i],nums[i]);
        
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n,INT_MIN);
        int best = INT_MIN;
        for(int i =0 ;i< nums.size();i++){
            best = max(total(nums,i,sum),best);
        }
        return best;
        
    }
};