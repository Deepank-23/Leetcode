class Solution {
public:
    int dps(string &word1,string &word2,int i,int j,vector<vector<int>> &dp){
        if(i==-1) return j+1;
        if(j==-1) return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j])return dp[i][j]= dps(word1,word2,i-1,j-1,dp);
        else {
            int a = dps(word1,word2,i-1,j,dp);
            int b = dps(word1,word2,i-1,j-1,dp);
            int c = dps(word1,word2,i,j-1,dp);
            return dp[i][j]=1+ min(a,min(b,c));
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return dps(word1,word2,word1.size()-1,word2.size()-1,dp);
    }
};