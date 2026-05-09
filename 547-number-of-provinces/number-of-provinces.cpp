class Solution {
    void dfs(vector<vector<int>> & isconnected, vector<int> &vis,int i ){
        int n =isconnected.size();
        vis[i] = true;
        for(int j=0;j<n;j++){
            if(isconnected[i][j]==1 && vis[j]==false){
                dfs(isconnected,vis,j);
                
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                
                dfs(isConnected,vis,i);
                count++;
            }
            

        }
        return count;
    }
};