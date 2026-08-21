class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<int> dp(n * n, -1);
        int maxm=0;
        int i=0;
        int j =0;
        int k=0;
        int maxlen = 0; 
        int start = 0;
        while(k!=n){
            while(i<n-k && j<n){
                if(i==j){
                    dp[i*n + j]=1;
                }
                
                
                else if(s[i]==s[j] && dp[(i+1)*n+(j-1)]!=0 ){
                    dp[i*n + j]=1;

                }
                else dp[i*n + j]=0;
                if (dp[i*n + j] && (j - i + 1) > maxlen) {
                    maxlen = j - i + 1;
                    start = i;
                }
                
                i++;
                j++;
            }
            k++;
            i=0;
            j=k;
        }
        
        return s.substr(start,maxlen);

    }
};