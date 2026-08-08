class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b){
            return a[0]<b[0];
        });

        vector<vector<int>>ans;
        vector<int> merged=intervals[0];
       

        for (int i =1;i<intervals.size();i++){
            const vector<int>& curr = intervals[i];
            if(curr[0]<=merged[1]){
                merged[1]=max(merged[1],curr[1]);
                
            }
            else{
                ans.push_back(merged);
                merged=curr;  
                }
        }
    ans.push_back(merged);
    return ans;

        
    }
};