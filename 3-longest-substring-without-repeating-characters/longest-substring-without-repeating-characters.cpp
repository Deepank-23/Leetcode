class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0;
        int len=0;
        unordered_map<char,int> lastseen;
        for (int i =0;i<s.size();i++){
            if(lastseen.find(s[i])!=lastseen.end()&& lastseen[s[i]]>=left){
                left = lastseen[s[i]]+1;

            }
            lastseen[s[i]]=i;
            len = max(len,i-left+1);

           
        }
        return len;
        
    }
};