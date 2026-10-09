class Solution {
public:
    void ways(string &curr,vector<string> &res,int n,int a,int b){
        if(curr.size()==2*n){
            res.push_back(curr);
            return ;
        }
        if(a<n){
            curr.push_back('(');
            ways(curr,res,n,a+1,b);
            curr.pop_back();
        }
        if(b<a){
            curr.push_back(')');
            ways(curr,res,n,a,b+1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;

        ways(curr,res, n ,0,0);
        return res;
        
    }
};