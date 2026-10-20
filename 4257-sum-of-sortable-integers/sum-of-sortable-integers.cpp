class Solution {
public:
    bool check(vector<int>&nums,int k ,int a,int curr){
        int n = nums.size();
        if (a >= n) return true;  
        int x=0;
        int mx=INT_MIN;
        int mn = INT_MAX;
        for(int i =a;i<a+k;i++){
            int nxt = nums[a + (i - a + 1) % k];
            if(nums[i]>nxt) x++;
            mn = min(mn,nums[i]);
            mx = max(mx,nums[i]);

        }
        if(x>1 || curr>mn)return false;
      

        return check(nums,k,a+k,mx);
        
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i =1;i<=n;i++){
            if(n%i==0 && check(nums,i,0,INT_MIN))ans+=i;
        }
        return ans;

        

    }
};