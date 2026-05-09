class Solution {
    void dfs(vector<vector<int>>& rooms,vector<int>&vis, int room){
       if(room>rooms.size()) return;
        vis[room]=true;


       
        
            for (int i : rooms[room]){
                if(!vis[i]){
                    vis[i]=1;
                    dfs(rooms,vis,i);

                }
            }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        dfs(rooms,vis,0);
        for(int i =0;i<n;i++){
            if(!vis[i])return false;
        }
        return true;
        
    }
};