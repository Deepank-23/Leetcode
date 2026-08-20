class Solution {
public:
    
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int i =0;
        int j=0;
        int k =0;
        int a = 0;
        while(k<n){
            while(i<n-k && j< n){
                if(i==j){
                    dp[i][j]=1;
                    a++;
                }
                else if(s[i]==s[j] && dp[i+1][j-1]!=0 ){
                    dp[i][j]=1;
                    a++;
                }
                else dp[i][j]=0;
                i++;
                j++;
            }
            k++;
            i=0;
            j=k;
        }
        
        
        return a ;
    }
};
