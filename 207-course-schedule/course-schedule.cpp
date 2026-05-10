class Solution {

    bool dfs(vector<vector<int>>& adj,vector<int>& path,vector<int>& vis,int node){
        vis[node]=1;
        path[node]=1;
        for(int i : adj[node]){
            
            if (!vis[i]) {
                if (dfs(adj, path, vis, i)) return true; // propagate cycle found
            } else if (path[i]) return true; // back edge = cycle
            
        }
        path[node]=0;
        return false;
        
    }

public:

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        // build graph
        for(int i=0; i<prerequisites.size(); i++){

            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }



        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i =0 ; i<numCourses;i++){
            if(!vis[i] && dfs(adj, path, vis, i)) return false;
           
        }

        return true;
    }
};