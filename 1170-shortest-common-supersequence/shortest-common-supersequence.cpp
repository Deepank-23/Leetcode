class Solution {
public:
    string lcs(string text1, string text2) {

            int n = text1.size();
            int m = text2.size();

            vector<vector<int>> dp(n+1, vector<int>(m+1,0));

            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    int p = (i>0&&j>0)?dp[i-1][j-1]:0;
                    int q = (i>0)?dp[i-1][j]:0;
                    int r = (j>0)?dp[i][j-1]:0;
                    if(text1[i-1] == text2[j-1]){
                        dp[i][j] = 1 + p;
                    }
                    else{
                        dp[i][j] = max(q,r);
                    }
                }
                
            }
            int i =n;
            int j =m;
            string s;
            while(i>0 &&j>0){
                if(text1[i-1]==text2[j-1]){
                    s.push_back(text1[i-1]); 
                    i--;
                    j--;
                } 
                else if(dp[i-1][j] >= dp[i][j-1]) i--;
                
                else j--;
            }
            


            reverse(s.begin(),s.end());
            
            return s;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string ans = lcs(str1,str2);
        string sub;
        int i=0;
        int j=0;
        int k=0;
        while(k<ans.size()){
            while(i<n){
                if(str1[i]==ans[k])break;
                else {
                    sub.push_back(str1[i]);
                    i++;
                }
            }
            while(j<m){
                if(str2[j]==ans[k])break;
                else {
                    sub.push_back(str2[j]);
                    j++;
                }
            }
            sub.push_back(ans[k]);
            i++;
            j++;
            k++;
        }
        while(i<n)sub.push_back(str1[i++]);
        while(j<m)sub.push_back(str2[j++]);
        return sub;
    }
};