class Solution {
public:
    int solve(string s,vector<int> &ways,int i){
        int n = s.size();
        if(i==s.size())return 1;
        if(s[i]=='0')return 0;
        if(ways[i]!=-1)return ways[i];

        int one = solve(s,ways,i+1);

        if(i+1<n){
            int two = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (two <= 26) one += solve(s, ways,i+2);  
        }
        return ways[i] = one;

    }
    int numDecodings(string s) {
        vector<int>ways(s.size(),-1);
        return solve(s,ways,0);
        
    }
};