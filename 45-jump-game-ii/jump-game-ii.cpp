class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int min = 0;
        int maxind=0;
        for(int i = 0;i<nums.size()-1;i++){
            maxind = max(maxind,i+nums[i]);
            if(i==end) {
                min++;
                end = maxind; 
            }      
            if(end>=nums.size()-1){
                break;
            }
        }
        return min;

        
    }
};