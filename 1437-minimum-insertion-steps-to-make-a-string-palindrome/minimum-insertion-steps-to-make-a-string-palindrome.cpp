class Solution {
public:
    int charact(string &s,int i , int j,vector<vector<int>>&dp){
        if(i==j)return 0;
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])return dp[i][j]=charact(s,i+1,j-1,dp);
        else return dp[i][j]= 1+ min(charact(s,i+1,j,dp),charact(s,i,j-1,dp));
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return charact(s,0,n-1,dp);
    }
};