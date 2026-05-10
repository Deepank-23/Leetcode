class Solution {
    void bfs(vector<vector<int>> &adj,vector<int>&indegree,vector<int>&res){
        queue<int> q;
        for(int i =0;i<adj.size();i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node= q.front();
            q.pop();
            res.push_back(node);
            for(int i :adj[node]){
                indegree[i]--;
                if(!indegree[i])q.push(i);
            }
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // build graph
        for(int i=0; i<prerequisites.size(); i++){

            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0; i<numCourses; i++){

            for(int j : adj[i]){

                indegree[j]++;
            }
        }

        
        vector<int> res;
        bfs(adj,indegree,res);
        if(res.size()<numCourses)return {};
    return res;

        
    }
};