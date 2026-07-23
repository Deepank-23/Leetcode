class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far=0;
        for(int i =0;i<=far;i++){
            far = max(far,nums[i]+i);
            if(far>=nums.size()-1)return true;
        }
        return false;
    }
};