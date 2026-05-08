class Solution {
    void bfs(vector<vector<int>>& rooms,vector<int>&vis){
        queue<int> q;
        vis[0]=true;
        q.push(0);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for (int i : rooms[curr]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);

                }
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        bfs(rooms,vis);
        for(int i =0;i<n;i++){
            if(!vis[i])return false;
        }
        return true;
        
    }
};