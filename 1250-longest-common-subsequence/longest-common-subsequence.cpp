class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(2, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int p = (i>0&&j>0)?dp[0][j-1]:0;
                int q = (i>0)?dp[0][j]:0;
                int r = (j>0)?dp[1][j-1]:0;
                if(text1[i] == text2[j]){
                    dp[1][j] = 1 + p;
                }
                else{
                    dp[1][j] = max(q,r);
                }
            }
            for(int j= 0;j<m;j++){
                dp[0][j]=dp[1][j];
            }
        }

        return dp[1][m-1];
}

};