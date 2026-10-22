class Solution {
public:
    int reverses(vector<int> nums,int op){
        reverse(nums.begin(),nums.end());
        if(is_sorted(nums.begin(),nums.end()))return op+1;
        int temp =nums[0];
        for (int i =0;i<nums.size()-1;i++){
            nums[i]=nums[i+1];
        }
        nums[nums.size()-1]=temp;
        if(is_sorted(nums.begin(),nums.end()))return op+2;
        return -1;
    }
    int rotate(vector<int> nums , int op){
        int temp =nums[0];
        for (int i =0;i<nums.size()-1;i++){
            nums[i]=nums[i+1];
        }
        nums[nums.size()-1]=temp;
        if(is_sorted(nums.begin(),nums.end()))return op+1;
        else if(is_sorted(nums.rbegin(),nums.rend()))return op+2;
        return -1;
    }
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        if(is_sorted(nums.begin(),nums.end()))return 0;
        int p = 0;
        for(int i =0;i<n;i++){
            if(nums[i]==0)p=i;
        }

        bool asc= true;
        bool desc = true;
        for(int i =0;i<n-1;i++){
            int up = nums[i]+1;
            if(up==n)up= 0;

            int down = nums[i]-1;
            if(down<0) down =n-1;

            if(nums[i+1]!=up)asc=false;
            if(nums[i+1]!=down)desc=false;
        }

        if(asc){
            if(p==0)return 0;
            return min(p,n-p+2);

        }
        if(desc){
            int q = n-1-p;
            return 1+min(q,p+1);
        }

        return -1;






    }
};