class Solution {
public:
    int dps(string &word1,string &word2,int i ,int j,vector<vector<int>>& dp){
        if(i==word1.size()||j==word2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j])return dp[i][j]= 1+dps(word1,word2,i+1,j+1,dp);
        else return dp[i][j]= max(dps(word1,word2,i+1,j,dp),dps(word1,word2,i,j+1,dp));
    }
    int minDistance(string word1, string word2) {
        int n = word2.size();
        
        vector<vector<int>>dp(word1.size(),vector<int>(n,-1));
        return (word1.size()-dps(word1,word2,0,0,dp))+(word2.size()-dps(word1,word2,0,0,dp));
    }
};