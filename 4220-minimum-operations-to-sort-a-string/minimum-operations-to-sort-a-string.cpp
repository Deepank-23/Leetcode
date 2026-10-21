class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(is_sorted(s.begin(),s.end()))return 0;
        if(n==2)return -1;
        int a = *min_element(s.begin(),s.end());
        int b = *max_element(s.begin(),s.end());
        if(a==s[0] || b== s[s.size()-1])return 1;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == a || s[i] == b) return 2;
        }
        return 3;
        
    }
};