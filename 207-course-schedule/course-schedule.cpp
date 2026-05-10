class Solution {

    bool bfs(vector<vector<int>>& adj,
             vector<int>& indegree,
             vector<int>& vis,
             vector<int>& res){

        queue<int> q;

        int n = adj.size();

        // push indegree 0 nodes
        for(int i=0; i<n; i++){

            if(indegree[i] == 0){

                q.push(i);

                vis[i] = 1;
            }
        }

        while(!q.empty()){

            int front = q.front();

            q.pop();

            res.push_back(front);

            for(int j : adj[front]){

                indegree[j]--;

                if(indegree[j] == 0 &&
                   !vis[j]){

                    q.push(j);

                    vis[j] = 1;
                }
            }
        }

        return res.size() == n;
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

        vector<int> indegree(numCourses,0);

        // calculate indegree
        for(int i=0; i<numCourses; i++){

            for(int j : adj[i]){

                indegree[j]++;
            }
        }

        vector<int> vis(numCourses,0);

        vector<int> res;

        return bfs(adj,indegree,vis,res);
    }
};