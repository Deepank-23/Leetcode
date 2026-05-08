class Solution {

    void bfs(vector<vector<int>>& adj,
             int sr,
             vector<int>& vis){

        queue<int> q;

        q.push(sr);

        vis[sr] = true;

        while(!q.empty()){

            int curr = q.front();

            q.pop();

            for(int x : adj[curr]){

                if(!vis[x]){

                    vis[x] = true;

                    q.push(x);
                }
            }
        }
    }

public:

    bool validPath(int n,
                   vector<vector<int>>& edges,
                   int source,
                   int destination) {

        if(source == destination)
            return true;

        // adjacency list
        vector<vector<int>> adj(n);

        for(int i=0; i<edges.size(); i++){

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);

            adj[v].push_back(u);
        }

        vector<int> vis(n,0);

        bfs(adj,source,vis);

        return vis[destination];
    }
};