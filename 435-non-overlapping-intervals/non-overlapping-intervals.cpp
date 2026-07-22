class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b){
            return a[1]<b[1];
        });

        int count=0;
        int lastend=-999999;
        for(int i=0;i<intervals.size();i++ ){
            if(intervals[i][0]<lastend){
                count++;
            }
            else lastend= intervals[i][1];
        }
    return count;
    
    }
};